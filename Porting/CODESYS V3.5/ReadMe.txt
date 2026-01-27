FUNCTION_BLOCK ReadMe

VAR
//ERROR DOWNLOAD !!! COMPILE OK!
//como1 :COM.Open ; //Serial free protocol
//comc1 :COM.Close; //Serial free protocol
//comw1 :COM.Write; //Serial free protocol
//comr1 :COM.Read ; //Serial free protocol
//GetDateAndTime_0: DTU.GetDateAndTime; //RTC
END_VAR

//VAR_GLOBAL PERSISTENT RETAIN !!!COMPILE WARNING!!!
//MB_TCP_SL1_HR0 AT %QD17 :REAL := 0.0; //NOT WORK!!!
//END_VAR

(*

-Базовая настройка связи и переферии.
https://modbus.pro/katalog/item/s3351_stkit2_startovyy_nabor_kontrollera_odot_automation_codesys_3_5_protsessor_analogovye_moduli_8_/
CODESYS 64 3.5.19.0.7z
C3351-A00-20230705.devdesc.xml
PlcIoDrv20230705.devdesc.xml
https://www.odotautomation.com/downloads_catalog/odot-plc/
IO-Config-V1.0.1.6-20230606-Fully-with-.NET4_.0.rar
GSDML-V2.33-ODOT-BLADEIO-TEST-20230606.oml

-Портирование библиотеки LIB_PLC.
https://github.com/DIYPLC/LIB_PLC
-Использование SIMATIC CONT_S FB42.

-Портирование библиотеки OSCAT BASIC 3.31.
http://www.oscat.de/de/component/jdownloads/category/2-oscat-basic.html?Itemid=0
https://oscat.ru/
https://ftp.owen.ru/CoDeSys3/98_Books/oscat_basic333_ru.pdf
-Использование OSCAT CTRL_PID

-Визуализация для тестирования.

-Использование часов RTC не поддерживается.
Библиотека: CAA DTUtil Extern
Функция: DTU.GetDateAndTime
Результат: функция не пддерживается, компилируется без ошибок, ошибка при попытке загрузки в ПЛК.

-Использование пользовательского протокола связи для порта RS485.
Библиотека: CAA SerialCom
Функция: COM.Open / COM.Write
Результат: функция не подерживается, компилируется без ошибок, ошибка при попытке загрузки в ПЛК.

-Использование VAR_GLOBAL RETAIN не понятен механизм записи и ресурс памяти ~RPI.

-Использование MODBUS TCP CLIENT / SERVER

-Использование MODBUS RTU MASTER / SLAVE

-Использование циклической задачи с минимальным временем скана.

-TODO OPC UA не поддерживается.
https://youtu.be/iO5phx9zENM?si=ObPzl5NVIcSBTfLO

- 0/0 inf nan check

-годен для замены локальных элемеров минитермов овнов.

*)
;