from fastapi import APIRouter, UploadFile, File, Form
from services import asr, alignment, tajweed, scoring, tafsir
import uuid, tempfile, shutil

router = APIRouter()

@router.post("/analyze")
async def analyze_recitation(
    audio: UploadFile = File(...),
    expected_surah: int | None = Form(None),
):
    # 1. Kaydet
    tmp_path = f"/tmp/{uuid.uuid4()}.wav"
    with open(tmp_path, "wb") as f:
        shutil.copyfileobj(audio.file, f)
    # 2. ASR
    asr_result = asr.transcribe(tmp_path)
    # 3. Ayet eşleştirme
    matched = alignment.match_verses(asr_result["text"], expected_surah=expected_surah)
    # 4. Harf zamanları (varsa refine)
    char_alignment = alignment.force_align(tmp_path, matched["text_ar"])
    # 5. Tecvid analiz
    tajweed_report = tajweed.evaluate(char_alignment, matched)
    # 6. Puanlama
    score = scoring.compute(tajweed_report, asr_result, matched)
    # 7. Meal / Tefsir
    tafsir_data = tafsir.fetch(matched["surah"], matched["ayahs"])
    return {
        "transcript": asr_result,
        "matched": matched,
        "alignment": char_alignment,
        "tajweed": tajweed_report,
        "score": score,
        "tafsir": tafsir_data
    }