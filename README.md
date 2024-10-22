# Simple API with CrowCpp

Bu proje, **CrowCpp** kullanarak basit bir RESTful API uygulamasıdır. Uygulama, notlar oluşturmanıza ve listelemenize olanak tanır ve Docker ile konteynerleştirilmiştir.

## Özellikler

- **`/hello`**: "Merhaba Dünya!" mesajı döndürür.
- **`/notes`**: Notları oluşturmanıza ve listelemenize olanak tanır.

## Gereksinimler

- **C++14** veya üstü
- **CMake** (3.5 veya üstü)
- **Boost** kütüphanesi
- **Asio** veya **Boost.Asio**
- **Docker** (opsiyonel, Docker kullanacaksanız)
- **Git** (opsiyonel)

## Kurulum ve Çalıştırma

### 1. Kaynak Kodunu Klonlayın

```bash
git clone https://github.com/your_username/your_repository.git
cd your_repository
