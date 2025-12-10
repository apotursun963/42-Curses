
# Conventional Commits (Geleneksel commitler)
Conventional Commits, **commit mesajlarını standart bir kurala göre yazmamızı sağlayan** bir yöntemdir.
Amaç: **Daha düzenli bir commit geçmişi**, **otomatik versiyonlama (semantic versioning)** ve **herkesin aynı dili konuşması**.

Aşağıdaki gibi *basit bir formatı* vardır:

```
<type>: <kısa açıklama>

<body> (isteğe bağlı)
<footer> (isteğe bağlı)
```

---

# ✅ 1. Type (Tür) Nedir?

Commit mesajı her zaman bir “type” ile başlar. Bu, commit'in ne tür bir değişiklik yaptığını gösterir.

En yaygın kullanılanlar:

| Type         | Ne demek?                   | Ne zaman kullanılır?                                                       |
| ------------ | --------------------------- | -------------------------------------------------------------------------- |
| **feat**     | Feature (Yeni özellik)      | Uygulamaya yeni bir özellik eklendiğinde                                   |
| **fix**      | Hata düzeltme               | Bug / error çözüldüğünde                                                   |
| **docs**     | Dokümantasyon               | README, yorum satırları, açıklamalar                                       |
| **style**    | Kod stil düzeni             | Virgül, boşluk, noktalı virgül, linter hatası… (kod mantığını değiştirmez) |
| **refactor** | Kod iyileştirme             | Mantık aynı kalır ama kod yeniden düzenlenir                               |
| **perf**     | Performans                  | Performansı artıran değişiklikler                                          |
| **test**     | Test ekleme/düzenleme       | Jest, pytest, unit test                                                    |
| **chore**    | Proje ayarları              | Config, .gitignore, package.json script gibi işlerle ilgili                |
| **build**    | Build sistem değişiklikleri | Webpack, vite, tsc, CI/CD ayarları                                         |
| **ci**       | Continuous Integration      | GitHub Actions, GitLab CI değişiklikleri                                   |

---

# ✅ 2. Örnek Commit Mesajları (En anlaşılır örnekler)

### ✔ Yeni özellik ekledin:

```
feat: kullanıcı profil sayfası eklendi
```

### ✔ Hata çözdün:

```
fix: giriş yaparken oluşan token hata düzeltildi
```

### ✔ Kod temizliği yaptın:

```
refactor: login fonksiyonu sadeleştirildi
```

### ✔ Dokümantasyonu güncelledin:

```
docs: README'ye kurulum adımları eklendi
```

### ✔ Stil düzeni:

```
style: indent ve boşluk hataları düzeltildi
```

---

# ✅ 3. Neden Conventional Commits Kullanılır?

### 1️⃣ **Commit geçmişi düzenli olur**

Kimin ne yaptığını anlamak kolaylaşır.

### 2️⃣ **Otomatik versiyonlama yapılabilir**

Örn. *feat* → minor version artırır
*fix* → patch artırır
*breaking change* → major artırır

### 3️⃣ **Takım içi iletişim kolaylaşır**

Herkes aynı formatta commit attığı için kimse "Bu commit ne yapıyor?" diye sormaz.

### 4️⃣ **CI/CD otomasyonları düzgün çalışır**

---

# 🚨 4. BREAKING CHANGES (Yıkıcı değişiklik)

Eğer commit geriye dönük uyumsuzluk yaratıyorsa şöyle yapılır:

```
feat!: API endpoint yapısı tamamen değiştirildi
```

veya footer’da:

```
feat: kullanıcı modeli güncellendi

BREAKING CHANGE: user_id artık string yerine uuid
