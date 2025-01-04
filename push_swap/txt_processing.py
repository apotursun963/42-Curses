
"""
Metin işleme (Text Preprocessing), doğal dil işleme projelerinde veriyi temizleyip analiz 
için uygun hale getirmek amacıyla yapılan bir dizi adımdır.
"""

# Metin işleme yöntemleri

## 1. Küçük Harfe Dönüştürme
# Metindeki tüm harfleri küçük harfe çevirerek kelimeler arasındaki farkları ortadan kaldırmak. 
# Örneğin, "KEDİ" ve "kedi" kelimeleri aynı kabul edilir.

text = "Bu BİR teSt METİNDİR"
txt_lwr = text.lower()
print(txt_lwr)


## 2. Noktalama İşaretlerini Kaldırma
# Metindeki noktalama işaretlerini kaldırmak, kelimelerin anlamını etkilemeyen karakterlerin 
# veri setinden çıkarılmasını sağlar.

import string

text = "Merhaba! Nasılsınız? Bugün hava @çok güzel."
text_no_punctuation = text.translate(str.maketrans('', '', string.punctuation))
print(text_no_punctuation)


## 3. Stopwords Kaldırma
# Stopwords, anlam taşıması düşük olan ve genellikle metin analizinde çıkarılan kelimelerdir 
# (örneğin: "ve", "bir", "bu"). Bu kelimeleri kaldırmak, modelin daha anlamlı verilerle çalışmasını sağlar.
# import nltk
# from nltk.corpus import stopwords
# bu kütüphane türkçe dilindeki etkisiz kelimeleri (stopwords) işlem ypapmak için kullanılır

from sklearn.feature_extraction.text import ENGLISH_STOP_WORDS

text = "This is a sample text."
words = text.split()        # varsayılan olarak ' ' olarak böler
filtered_words = []
for word in words:
    if word.lower() not in ENGLISH_STOP_WORDS:
        filtered_words.append(word)
print(" ".join(filtered_words))


## 4. Lemmatizasyon: kelimeleri köklerine indirgerken anlamlı bir şekilde yapar.
## 5. Stemming: kelimeleri köklerine indirger, ancak anlamlı olup olmadıklarına bakmaz
## 6. Tokenizasyon: Metni kelimelere veya cümlelere ayırma işlemi
## 7. Özel Karakterlerin Temizlenmesi: emoji, semboller
## 8. Sayılardan Kurtulma: Metindeki sayılar, çoğu NLP uygulaması için gereksiz olabilir. 
## 9. Kelime Vektörizasyonu (Vectorization): Metni sayısal verilere dönüştürmek için kullanılan bir tekniktir.

# -----------------------re kütüphanesi-------------------

import re

text = "Merhaba, benim ismim apo."
pattern = r"Merhaba"

match = re.match(pattern, text) 
print(match)

# re.match(): Deseni sadece metnin başında arar.
# re.search(): Deseni metnin herhangi bir yerinde arar.
# re.findall(): Metindeki tüm eşleşmeleri liste olarak döndürür.
# re.sub(): Deseni başka bir metinle değiştirir.
# re.split(): Desene göre metni böler.

text = r"Merhaba\nDünya"
print(text)