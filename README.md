Device-Free Indoor People Counting Using Wi-Fi   Channel State Information for Internet of Things

  Selcan Kebelio�lu, Sinem Ezgi Tutuman , Melike Ayd�n, Feyzanur Kuzucu, Ay�e Nur Akman , Ya�mur �atak
 Bilgisayar M�hendisli�i B�l�m�(2.��retim)
Kocaeli �niversitesi





�zet

Bu projede amac�m�z Wifi teknolojisini kullanarak ortamda bulunan ,wifi vericisine ba�lanan al�c�lar� tespit etmek ve wifi vericisine ba�lananan ki�i say�s�n� bulmakt�r.Bu projeyi kullan�c�,m��teri say�s� belirlemek isteyen yerlerde, acil durum ve afetlerde ki�ilerin nerede oldu�unu belirlemek amac�yla kullanabiliriz.


1. Giri�

Kapal� alanlarda insan say�m�,yo�unluk �nemlidir.Trafik y�netimi,ya�l�lar�n izlenmesi,konferansa kat�l�m say�s� vb,bilgileri eri�mek i�in bu uygulama kullan�lmaktad�r.Kablosuz sinyallerle bu problemi ��zmek m�mk�nd�r.Kablosuz sinyaller kullanlarak kapal� alanda ki�i say�s�n�n belirlenmesi NodeMCU yard�m�yla m�mk�n olur.
Wifi gibi kablosuz cihazlar kullan�larak ba�ka bir ekipmana gerek duyulmamaktad�r.NodeMCU ile elde edilen veriler Firebase 'e kay�t edilir.Kay�t edilen veriler MIT App Inventor ile aray�ze aktar�l�r.


2. Temel Kavramlar
Projemizi geli�tirmek i�in a�a��daki malzemeleri ve ortamlar� kulland�k.




NodeMCU  Ve  ESP 8266 :



                                      �ekil 1.0

Arduino, programlayabildi�imiz bir davre kart�d�r.NodeMCU ise Arduino, Arduino IDE uygulamas�ndan programlayabildi�imiz i�inde ESP8266 bulunduran bir devre kart�d�r.�Programlanabilirdir, d���k maliyetli ve basittir. Ayr�ca ak�ll� bir cihazd�r ve WI-FI ba�lant�ya yani kablosuz ba�lant�ya ve kullan�ma haz�r gelir.
�zellikleri ;
CPU  : 80MHz(varsay�lan) veya 160MHZ
Bellek :64 KB ,   Wireless Standart : 802.11 b/g/n
GPIO : 16 Pin
Haberle�me Protokol�: SPI,12C,UART
Analog Pin : 10 Bit ADC  ,    G�� : 3.3 VDC

Firebase:

JSON�verilerimizi uzak bir sunucuda�ger�ek zamanl� olarak�depolayabildi�imiz,�bulut (Cloud) tabanl��bir platformdur. Firebase; sunucu taraf�nda�(BackEnd)�bize sa�lam�� oldu�u servis deste�i sayesinde, veri taban�nda ger�ekle�en her de�i�iklikten an�nda haberdar olabilmemizi m�mk�n k�lmaktad�r. Firebase'de android uygulamas�ndan ve ESP'den de�erler saklan�r. Daha sonra baz� fonksiyonlar kullan�larak de�erlere ESP ve uygulama taraf�ndan eri�ilir. Bu de�erlere eri�mek i�in �zel kimlik do�rulama anahtar� gerekir.

Donan�m platformu olarak Arduino IDE ile programlanan NodeMCU 1.0 Development Board'u (ESP 8266 tabanl�) kulland�k.
Veritaban�n� olu�turmak i�in ad�mlar;

1) https://console.firebase.google.com/  sitesinden �get started� butonu y�nlendirir.[9]

2) Add Project butonunu se�eriz.


3) Proje ismini girip, proje olu�tururuz.

4) A��lan sayfadan �database�i se�eriz.


5) Veritaban� se�ene�ini se�tikten sonra, bir sonraki sayfada a�a�� kayd�r�p, ger�ek zamanl� veritaban� olu�tur ��esini se�ip kilitli modda olu�tururuz.

6) GUI'de bulunan k���k art� (+) i�aretlerini kullanarak veritaban�na alt ��eler ekleyebiliyoruz.

7) Herhangi bir cihaz�n veritaban�m�za eri�ebilmesi i�in veritaban�n�n kurallar�n� de�i�tirmemiz gerekiyor. Bunu yapmak i�in kurallar sekmesine gidip a�a��daki gibi kodu de�i�tiriyoruz.


8) Daha sonra bir proje olu�turuyorup Donan�m Platformunu Yap�land�r�yoruz.
NodeMCU�yu do�ru bir �ekilde ayarlad�ktan sonra. WiFi Router'�m�za / Hotspot'umuza ba�lanmak i�in basit bir kod y�kleyerek test edilebilir.

9) Donan�m� Veritaban�na Ba�lamak.
Arduino'yu veritaban�na ba�lamak i�in Firebase Arduino K�t�phanesi'ni kulland�k.[9]

MIT  Android uygulamas�:

App Inventor�ba�lang��ta Google taraf�ndan olu�turulan daha sonralar� ise Massachusetts Institute of Technology (MIT) taraf�ndan desteklenen a��k kaynakl�(open source) bir web uygulamas�d�r. App Inventor�,�T�rk�e�ye uygulama mucidi olarak �evrilmi�tir. App Inventor�yeni ba�layanlar i�in kolayl�kla Android uygulama geli�tirmesine olanak sa�lar. Uygulamam�zda bu yaz�l�m� kulland�k.

3. S�STEM TASARIMI VE UYGULAMASI 

�ncelikle �http://arduino.esp8266.com/stable/package_esp8266com_index.json� url sini Arduino uygulamas�ndan Dosya>Tercihler>Ek Devre Kart� Y�neticisi URL�ri b�l�me yaz�yoruz.
Kart>KartY�neticisi>Aramalar�n�z� Filtreleyin>ESP8266 yaz�p ��kan �eyi indiriyoruz. B�ylece nodeMCU kart�n� aktifle�tirmi� oluyoruz.

                             �ekil 1.1

Projemizde ESP 8266'y� wifi mod�l� olarak kulland�k.  ESP 8266 da Wifi kullan�c�n�n ba�lanaca�� ba�lant� ad�m�z� ve �ifremizi belirledik.Ard�ndan sonu� de�i�keninde wifi parola ve �ifresi uyan cihazlar� kontrol ederek say�s�n� ve IP adresini ekrana yazd�rd�k.Firebase k�t�phanesini Arduino 'a ekleyerek buldu�umuz verileri (kullan�c� IP adresleri ve ki�i say�s�) Firebase veritaban�na kaydettik.Kaydedilen verileri MIT App �nventorda bir aray�z olu�turarak kullan�c� aray�z�n� olu�turmu� olduk.
Kodumuzu inceleyecek olursak;

�ncelikle #include <ESP8266WiFi.h>
#include <FirebaseArduino.h> k�t�phanelerimizi tan�mlar�z.
Ard�ndan wifi ad�n� ve pasaport ad�n� tan�mlar�z.Wifi adresimiz ve pasaportumuz bu tan�mlanan veriler olacakt�r. #define FIREBASE_HOST "deneme-eb804.firebaseio.com" �eklinde firebasedeki proje adlar�m�z� ve ba�lant�y� sa�lamak i�in gerekli �ifreyi tan�mlar�z.
Setup() fonksiyonu i�inde WiFi.begin(WIFI_SSID, WIFI_PASSWORD); �eklinde ba�lant� sa�lar�z.

#define FIREBASE_AUTH "41MqeGfErOCACpyb290ZMr0ekRDvdKjusCHqrxMn" �ifremizi ald���m�z yer a�a��da g�sterilmi�tir.


Ard�ndan ba�lanma durumunu kod i�erisinde kontrol ederek ba�lan�lan IP adreslerini yazd�r�yoruz.
Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH); kodu ile firebase ba�lant�s�n� �al��t�r�r�z.
Loop i�erisinde  Serial.printf("Ba�lanan Ki�i Say�s� = %d\n", WiFi.softAPgetStationNum());
Firebase.setFloat("number", number);  kodlar�yla
 ba�lanan ki�i say�s�n� arduino ekran�na ve firebase'e bu �ekilde yazd�rm�� oluruz.

5. SONU�
Projemizin sonucunda wifi ba�lant�s� i�indeki ki�ileri ve toplam ki�i say�s�n� buluyoruz. 
  6.KAYNAK�A

[1] http://umutonur.com/firebase-nedir-nasil-kullanilir-ve-ozellikleri-nelerdir/
[2] 
[3] https://maker.robotistan.com/esp8266-ile-iot-dersleri-1-esp8266-modulunu-guncelleme/

[4] https://www.artistanbul.io/blog/2016/09/29/app-inventor-nedir-nicin-onemlidir/

[5] https://www.technopat.net/2013/05/20/app-inventor-programlamaya-giris/

[6] http://www.kodlamadersi.com/mobil-uygulama-gelistirme-app-inventor.html

[7] https://firebase.google.com/

[8] https://medium.com/coinmonks/arduino-to-android-real-time-communication-for-iot-with-firebase-60df579f962
1


3


