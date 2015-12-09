<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE TS><TS version="1.1" language="ru_RU">
<context>
    <name>instWizard</name>
    <message>
        <location filename="../src/instwizard.cpp" line="59"/>
        <source>Driver : </source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/instwizard.cpp" line="65"/>
        <source>Select Device : </source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/instwizard.cpp" line="68"/>
        <source>start search from : </source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/instwizard.cpp" line="71"/>
        <source>Possible Hits :</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/instwizard.cpp" line="77"/>
        <source>search driver</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/instwizard.cpp" line="82"/>
        <source>Click to select a folder from where the search should start ...</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/instwizard.cpp" line="86"/>
        <source>Click to open the offline ndiswrapper wiki</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/instwizard.cpp" line="89"/>
        <source>Start Installation</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/instwizard.cpp" line="90"/>
        <source>Start the installation of the selected windows driver.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/instwizard.cpp" line="93"/>
        <source>Cancel Installation</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/instwizard.cpp" line="94"/>
        <source>Cancel the installation.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/instwizard.cpp" line="157"/>
        <source>Select the directory to start the search from ...</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/instwizard.cpp" line="207"/>
        <source>Possible Hits : </source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/instwizard.cpp" line="229"/>
        <source>WARNING</source>
        <translation type="unfinished">ПРЕДУПРЕЖДЕНИЕ</translation>
    </message>
    <message>
        <location filename="../src/instwizard.cpp" line="229"/>
        <source>You must select a driver from the list first!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/instwizard.cpp" line="31"/>
        <source>The wizard will help you to locate the appropriate inf-file and the according sys-file for the installation of the windows driver.

First select the proper device from the device list.

By pressing the button right to the list, the offline file from the ndiswrapper wiki (card known to work) is displayed. You maybe find helpful information for your hardware.

Next you have to tell the wizard from where to start the search run. If you got a dual boot system and the appropriate driver is already installed in the windows system you may mount the windows partition and give the mountpoint as starting point for the search run.

The result of the search run is displayed in the list below.
Select a driver from the list and press the install button.

The wizard even tries to find the correct sys-file if it is not located in the same folder as the inf-file.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/instwizard.cpp" line="34"/>
        <source>KNDISWrapper Installation Wizard</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/instwizard.cpp" line="45"/>
        <source>Installation Wizard</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/instwizard.cpp" line="104"/>
        <source>No.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/instwizard.cpp" line="105"/>
        <source>Path</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/instwizard.cpp" line="251"/>
        <source>ERROR</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/instwizard.cpp" line="251"/>
        <source>The file &quot;</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/instwizard.cpp" line="251"/>
        <source>&quot; is required and was not found in &quot;</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/instwizard.cpp" line="251"/>
        <source>&quot;.
I will try to find the file in the given searchpath (1 level up).</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/instwizard.cpp" line="291"/>
        <source>Attention</source>
        <translation type="unfinished">Внимание</translation>
    </message>
    <message>
        <location filename="../src/instwizard.cpp" line="287"/>
        <source>Found a matching file. Try to continue the installtion</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/instwizard.cpp" line="291"/>
        <source>No matching file was found. Installation aborted!</source>
        <translation type="unfinished"></translation>
    </message>
</context>
<context>
    <name>kndiswrapper</name>
    <message>
        <location filename="../src/kndiswrapper.cpp" line="48"/>
        <source>KNDISWrapper will help you to setup your wireless network with ndiswrapper.

The Install Driver Button is used to install a new driver for a wireless dvice supported by ndiswrapper. To do so, you have to identify the appropriate &apos;.inf&apos; file. Sometimes you find this file on the driver-CD delivered together with the hardware. In some cases this file is stored in a &apos;.cab&apos; file. This is a Windows archive file and can be extracted with &apos;cabextract&apos;. If the driver is delivered only in a &apos;.exe&apos; setup-file you can &apos;only install the driver under Windows and look for the driver in the Windows Directory.

The Remove Driver Button is used to remove a Windows driver that doesn&apos;t work or isn&apos;t used any longer.
A copy of the driver is made so it can be restored if needed.

With the Reload List Button the driver list is loaded again. Changes (e.g. hardware installed) are not detected automaticly.

With the Restore Driver Button you can re-install a driver, previously removed through the Remove Button

Config Network invokes the network configuration dialog. Here you can setup the interface associated to the driver you have selected in the list.

With the Quit Button you exit this application.</source>
        <translation>KNDISWrapper поможет Вам настроить Вашу беспроводную сеть через ndiswrapper.

Кнопка «Добавить драйвер» используется для установки беспроводного устройства поддерживаемого ndiswrapper. Для этого Вам нужно найти &apos;.inf&apos; файл. Зачастую он находится на CD диске прилагаемого к устройству. Иногда этот файл запакован в &apos;.cab&apos; файл. Это Windows архив и его можно распаковать с помощью &apos;cabextract&apos;. Если драйвер находится в &apos;.exe&apos; установочном файле, то вы можете извлечь его только в Windows и найти его в Windows директории.

Кнопка «Удалить драйвер» используется для удаления Windows драйвера, если он больше не нужен или его работа некорректна.
Восстановить этот драйвер можно будет из сохраненной копии.

С помощью кнопки «Вернуть драйвер» Вы можете переустановить драйвер после его удаления.

«Настройка сети» вызывает диалог настройки сети. Там Вы можете настроить интерфейс, ассоциированный с драйвером.

Кнопка «Выход» закрывает программу.</translation>
    </message>
    <message>
        <location filename="../src/kndiswrapper.cpp" line="82"/>
        <source>Add Driver</source>
        <translation>Добавить драйвер</translation>
    </message>
    <message>
        <location filename="../src/kndiswrapper.cpp" line="305"/>
        <source>Remove Driver</source>
        <translation>Удалить драйвер</translation>
    </message>
    <message>
        <location filename="../src/kndiswrapper.cpp" line="113"/>
        <source>Reload List</source>
        <translation>Обновить список</translation>
    </message>
    <message>
        <location filename="../src/kndiswrapper.cpp" line="87"/>
        <source>Module Check</source>
        <translation>Проверить модуль</translation>
    </message>
    <message>
        <location filename="../src/kndiswrapper.cpp" line="88"/>
        <source>Info dmesg</source>
        <translation>Сообщения dmesg</translation>
    </message>
    <message>
        <location filename="../src/kndiswrapper.cpp" line="122"/>
        <source>Config Network</source>
        <translation>Настройка сети</translation>
    </message>
    <message>
        <location filename="../src/kndiswrapper.cpp" line="100"/>
        <source>Right-Click for more options</source>
        <translation>Правый клик для дополнительных опций</translation>
    </message>
    <message>
        <location filename="../src/kndiswrapper.cpp" line="333"/>
        <source>Install Driver</source>
        <translation>Добавить драйвер</translation>
    </message>
    <message>
        <location filename="../src/kndiswrapper.cpp" line="107"/>
        <source>Install a new driver. Therefor locate the appropriate .inf file.</source>
        <translation>Установка нового драйвера. Для этого определите местонахождение .inf файла.</translation>
    </message>
    <message>
        <location filename="../src/kndiswrapper.cpp" line="111"/>
        <source>Removes the selected driver in the list.</source>
        <translation>Удаляет выбранный драйвер из списка.</translation>
    </message>
    <message>
        <location filename="../src/kndiswrapper.cpp" line="115"/>
        <source>Reload the content of the list</source>
        <translation>Перезагружает список драйверов.</translation>
    </message>
    <message>
        <location filename="../src/kndiswrapper.cpp" line="117"/>
        <source>Restore Driver</source>
        <translation>Вернуть драйвер</translation>
    </message>
    <message>
        <location filename="../src/kndiswrapper.cpp" line="119"/>
        <source>Restores a removed driver.</source>
        <translation>Восстанавливает удаленный драйвер.</translation>
    </message>
    <message>
        <location filename="../src/kndiswrapper.cpp" line="124"/>
        <source>Start&apos;s the network configuration dialog</source>
        <translation>Запускает настройку сети.</translation>
    </message>
    <message>
        <location filename="../src/kndiswrapper.cpp" line="127"/>
        <source>Quit</source>
        <translation>Выход</translation>
    </message>
    <message>
        <location filename="../src/kndiswrapper.cpp" line="129"/>
        <source>Quit the application</source>
        <translation>Выход из программы</translation>
    </message>
    <message>
        <location filename="../src/kndiswrapper.cpp" line="305"/>
        <source>Are you sure you want to remove the driver : </source>
        <translation>Вы уверены что хотите удалить драйвер:</translation>
    </message>
    <message>
        <location filename="../src/kndiswrapper.cpp" line="333"/>
        <source>The driver has been succesfully installed</source>
        <translation>Драйвер успешно установлен</translation>
    </message>
    <message>
        <location filename="../src/kndiswrapper.cpp" line="652"/>
        <source>Warning</source>
        <translation>Предупреждение</translation>
    </message>
    <message>
        <location filename="../src/kndiswrapper.cpp" line="336"/>
        <source>The driver is already installed</source>
        <translation>Этот драйвер уже установлен</translation>
    </message>
    <message>
        <location filename="../src/kndiswrapper.cpp" line="339"/>
        <source>Error</source>
        <translation>Ошибка</translation>
    </message>
    <message>
        <location filename="../src/kndiswrapper.cpp" line="339"/>
        <source>Unable to install the driver!

</source>
        <translation>Невозможно установить драйвер!</translation>
    </message>
    <message>
        <location filename="../src/kndiswrapper.cpp" line="341"/>
        <source>Unkown outcome!
</source>
        <translation>Неизвестный результат!</translation>
    </message>
    <message>
        <location filename="../src/kndiswrapper.cpp" line="345"/>
        <source>Writeing of configuration failed!</source>
        <translation>Запись конфигурации неудалась!</translation>
    </message>
    <message>
        <location filename="../src/kndiswrapper.cpp" line="346"/>
        <source>Removing of ndiswrapper module failed!</source>
        <translation>Удалить модуль ndiswrapper неудалось!</translation>
    </message>
    <message>
        <location filename="../src/kndiswrapper.cpp" line="347"/>
        <source>Loading of ndiswrapper module failed!</source>
        <translation>Загрузка модуля ndiswrapper неудалась!</translation>
    </message>
    <message>
        <location filename="../src/kndiswrapper.cpp" line="388"/>
        <source>INF-Files (*.inf)</source>
        <translation>INF-файлы(*.inf)</translation>
    </message>
    <message>
        <location filename="../src/kndiswrapper.cpp" line="356"/>
        <source>Removed Drivers</source>
        <translation>Удаленные драйверы</translation>
    </message>
    <message>
        <location filename="../src/kndiswrapper.cpp" line="388"/>
        <source>Select a File</source>
        <translation>Выберите файл</translation>
    </message>
    <message>
        <location filename="../src/kndiswrapper.cpp" line="388"/>
        <source>New Driver</source>
        <translation>Новый драйвер</translation>
    </message>
    <message>
        <location filename="../src/kndiswrapper.cpp" line="412"/>
        <source>Removing Driver</source>
        <translation>Удаление драйвера</translation>
    </message>
    <message>
        <location filename="../src/kndiswrapper.cpp" line="412"/>
        <source>The driver has been succesfully removed</source>
        <translation>Драйвер успешно удален</translation>
    </message>
    <message>
        <location filename="../src/kndiswrapper.cpp" line="414"/>
        <source>Unable to remove the driver!
</source>
        <translation>Невозможно удалить драйвер!</translation>
    </message>
    <message>
        <location filename="../src/kndiswrapper.cpp" line="442"/>
        <source>Fatal Error</source>
        <translation>Критическая ошибка</translation>
    </message>
    <message>
        <location filename="../src/kndiswrapper.cpp" line="442"/>
        <source>ndiswrapper not found.
Please install ndiswrapper before you proceed.
Program aborting!</source>
        <translation>ndiswrapper не найден.
Пожалуйста, установите ndiswrapper перед продолжением.
Программа прервана!</translation>
    </message>
    <message>
        <location filename="../src/kndiswrapper.cpp" line="515"/>
        <source>Attention</source>
        <translation>Внимание</translation>
    </message>
    <message>
        <location filename="../src/kndiswrapper.cpp" line="468"/>
        <source>There is no alternativ driver for </source>
        <translation>Нет альтернативного драйвера для</translation>
    </message>
    <message>
        <location filename="../src/kndiswrapper.cpp" line="481"/>
        <source>A alternativ driver is loaded by the kernel. This may
prevent ndiswrapper from working properly. </source>
        <translation>Альтернативный драйвер загружен ядром. 
Это может препятствовать корректной работе ndiswrapper.</translation>
    </message>
    <message>
        <location filename="../src/kndiswrapper.cpp" line="482"/>
        <source>We have
to remove the loaded kernel module and blacklist the
kernel module so it</source>
        <translation>Мы удаляем
загруженный модуль из ядра и вносим его
черный список</translation>
    </message>
    <message>
        <location filename="../src/kndiswrapper.cpp" line="483"/>
        <source> will not be loaded by the kernel again.

Shall I try to fix the problem for you?</source>
        <translation>не будет загружен ядром снова.
Попытаться исправить эту проблему?</translation>
    </message>
    <message>
        <location filename="../src/kndiswrapper.cpp" line="497"/>
        <source>
Hints:
- I will do a : rmmod </source>
        <translation>
Подсказка:
- Делаем: rmmod </translation>
    </message>
    <message>
        <location filename="../src/kndiswrapper.cpp" line="497"/>
        <source>
- enter the name of the module into /etc/modprobe.d/blacklist
- and into /etc/modprobe.conf

</source>
        <translation>
- внести имя модуля в /etc/modprobe.d/blacklist
- и в /etc/modprobe.conf

</translation>
    </message>
    <message>
        <location filename="../src/kndiswrapper.cpp" line="515"/>
        <source>No conflicting kernel modules are loaded!
&gt;&gt;&gt;&gt;&gt; erverything is fine &lt;&lt;&lt;&lt;&lt;</source>
        <translation>Нет конфликта загруженного модуля с ядром!
&gt;&gt;&gt;&gt;&gt; все отлично &lt;&lt;&lt;&lt;&lt;</translation>
    </message>
    <message>
        <location filename="../src/kndiswrapper.cpp" line="538"/>
        <source>WARNING</source>
        <translation>ПРЕДУПРЕЖДЕНИЕ</translation>
    </message>
    <message>
        <location filename="../src/kndiswrapper.cpp" line="538"/>
        <source>The ndiswrapper module is not loaded.
ndiswrapper will not be able to identify any hardware.
Shall I load the kernel module for you?</source>
        <translation>Модуль ndiswrapper не загружен.
ndiswrapper не в состоянии обнаружить устройства.
Загрузить модуль в ядро?</translation>
    </message>
    <message>
        <location filename="../src/kndiswrapper.cpp" line="541"/>
        <source>Loading of the kernel module (ndiswrapper) failed!</source>
        <translation>Загрузка модуля (ndiswrapper) в ядро неудалась!</translation>
    </message>
    <message>
        <location filename="../src/kndiswrapper.cpp" line="598"/>
        <source>dmesg-Info</source>
        <translation>в сообщениях dmesg</translation>
    </message>
    <message>
        <location filename="../src/kndiswrapper.cpp" line="652"/>
        <source>Can&apos;t start the network configuration! No interface found!</source>
        <translation>Невозможно запустить настройку сети! Интерфейс не найден!</translation>
    </message>
    <message>
        <location filename="../src/kndiswrapper.cpp" line="89"/>
        <source>Offline Wiki</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/kndiswrapper.cpp" line="375"/>
        <source>Do you want to use the installation wizard or do you want to select the appropirate *.inf file by yourself</source>
        <translation type="unfinished"></translation>
    </message>
</context>
<context>
    <name>wifiSetup</name>
    <message>
        <location filename="../src/wifisetup.cpp" line="43"/>
        <source>Here you can setup various parameter for your wireless network

The mode of operation can be set to Ad-hoc for a peer-to-peer network without an Access-Point or to Managed for a network with an Access-Point.

Specify the essid for your network (either by scanning or entering manually). This information is needed to make your pc a part of a network cell.
If you use a managed network and do not use WPA as authentication you can leave this field empty. In this case the wifi-adapter uses the access-point with the best signal quality

Within a network you have to specify the authentication-mode. Here you can choose between WEP and WPA. WEP (Wired Equivalent Privacy) is a system for encryption of networks with optional authentication. Usually when using WEP, the mode WEP-Open is approriate (no authentication).

WEP is regarded insecure. Therefore WPA (Wifi Protected Access) was implemented. But not every hardware support WPA. WPA can only be uses in Managed mode.

You can enter the key in HEX, ASCII or a Passphrase.
If you use WEB as authentication mode you have to enter a 10 digit HEX value for a 64-bit key, a 26 digit HEX value for a 128-bit key, a 32 digit HEX value for a 156-bit key and 58 digits for a 256-bit key. You can alternatively enter a 5 characters for a 64-bit key, 13 characters for a 128-bit key, 16 characters for a 156-bit key and 29 characters for a 256-bit key. But keep in mind that not every hardware supports keys up to 256 bit.

If you use WPA you can enter the key in HEX. Therefore you have to enter a 64-digit Hex-key or you can alternatively enter a passphrase (8 - 63 characters)</source>
        <translation>Здесь Вы можете настроить различные параметры Вашей беспроводной сети.

Режим работы (mode) может быть установлен в режим «децентрализованной сети» (Ad-hoc) для соединений точка-точка (peer-to-peer) без точки доступа (Access-Point) или «Управляемый» (Managed) для сети с точкой доступа.

Укажите essid - уникальное имя вашей сети (выбрать после сканирования или с ввести вручную). Эта информация необходима, чтобы сделать Ваш компьютер частью сети. Если Вы используете Управляемую сеть без WPA аутентификации - можете оставить эти поля пустыми. В этом случае wifi-адаптер использует точку доступа с лучшим уровнем сигнала.

В сети с аутентификацией необходимо выбрать способ, это может быть WEP или WPA. WEP - система шифрования сетей с дополнительной аутентификацией. Обычно используется WEP, в режиме Wep-Open (без аутентификации).

Сейчас WEP расценивается как небезопасный протокол, и был заменен протоколом WPA. К сожалению не все устройства поддерживают протокол WPA. Протокол WPA может быть использован только в Управляемой (Managed) сети.

В качестве ключа Вы можете использовать шестнадцатеричные символы (HEX), набор символов (ASCII) или Контрольную фразу (Passphrase). 
Если Вы используете WEP аутентификацию, то Вы должны использовать: 10 шестнадцатиричных символов для 64-битного ключа, 26 шестнадцатиричных символов для 128-битного ключа, 32 шестнадцатиричных символов для 158-битного ключа, 58 шестнадцатиричных символов для 256-битного ключа. В качестве альтернативы Вы можете использовать 5 символов для 64-битного ключа, 13 символов для 128-битного ключа, 16 символов для 158-битного ключа, 29 символов для 256-битного ключа. Но имейте в виду, что не все устройства поддерживают 256-битные ключи.

Если Вы используете протокол WPA, то можете использовать шестнадцатеричный ключ. Для этого Вы должны ввести ключ длинной 64 шестандцатеричных символа или, в качестве альтернативы, ввести контрольную фразу (длиной от 8 до 63 символов).</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="50"/>
        <source>Device : </source>
        <translation>Устройство: </translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="71"/>
        <source>Read this for further information about how to setup your wireless lan</source>
        <translation>Прочтите эту информацию о настройке беспроводной сети</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="73"/>
        <source>Profile : </source>
        <translation>Профиль:</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="80"/>
        <source>If multiple configurations are found, you can select the active configuration</source>
        <translation>Если найдены разные конфигурация, Вы можете выбрать текущую конфигурацию</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="84"/>
        <source>Removes the actual configuration file</source>
        <translation>Удаление файла текущей конфигурации</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="86"/>
        <source>Key-Format</source>
        <translation>Формат ключа</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="87"/>
        <source>Select the way you want to enter your key</source>
        <translation>Выберите способ ввода ключа</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="97"/>
        <source>Config</source>
        <translation>Настройка</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="99"/>
        <source>Select whether you want to config interface with a static IP or via DHCP</source>
        <translation>Выберите как Вы хотите метод настройки интерфейса: статический IP или динамический IP через DHCP</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="100"/>
        <source>Static IP</source>
        <translation>Статический IP</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="101"/>
        <source>DHCP</source>
        <translation>Динамический IP</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="110"/>
        <source>Shows the number of character and whether the key is valid (green) or not (red)</source>
        <translation>Показывает число символов и проверяет верность ключа (зеленый - верно, красный - нет)</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="114"/>
        <source>Enter the hex-key or passphrase</source>
        <translation>Введите шестнадцатеричный ключ или контрольную фразу</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="117"/>
        <source>Mode of Operation</source>
        <translation>Режим сети</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="427"/>
        <source>ESSID</source>
        <translation>Сеть</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="119"/>
        <source>Authentication</source>
        <translation>Аутентификация</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="121"/>
        <source>Select a network or enter the ESSID manually</source>
        <translation>Выберите сеть или введите имя сети вручную</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="123"/>
        <source>Select which encryption mode you want to use</source>
        <translation>Выберите метод шифрования</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="140"/>
        <source>ESSID-Scan</source>
        <translation>Обзор</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="142"/>
        <source>Scan for available networks</source>
        <translation>Сканировать доступные сети</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="146"/>
        <source>Enter the name of your network (ESSID) manually</source>
        <translation>Введите имя Вашей сети вручную</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="155"/>
        <source>Required Programms:

</source>
        <translation>Необходимые программы:

</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="157"/>
        <source>IP-Addr : </source>
        <translation>IP адрес:</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="159"/>
        <source>Netmask : </source>
        <translation>Маска сети:</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="161"/>
        <source>Default GW (opt.) : </source>
        <translation>Основной шлюз:</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="163"/>
        <source>DNS Entry (opt)</source>
        <translation>Первичный DNS:</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="165"/>
        <source>sec. DNS (opt)</source>
        <translation>Вторичный DNS:</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="167"/>
        <source>pre Conf. Script</source>
        <translation>Вып. до:</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="169"/>
        <source>post Conf. Script</source>
        <translation>Вып. после:</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="171"/>
        <source>Nickname</source>
        <translation>Никнэйм</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="180"/>
        <source>Enter the static IP-Addr of the interface (192.168.2.1)</source>
        <translation>Введите статический IP адрес для интерфейса (например, 192.168.2.1)</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="183"/>
        <source>Enter the desired Netmask (255.255.255.0)</source>
        <translation>Введите маску сети (например, 255.255.255.0)</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="186"/>
        <source>(Optional) The IP Address of the Gateway (e.g. DSL Route to the internet)
If you have a working default Gateway you can ommit this field</source>
        <translation>(Необязательно) IP адрес шлюза (например, DSL роутера)
Заполните, если у Вы знаете адрес шлюза</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="192"/>
        <source>Optional a DNS Entry for the /etc/resolv.conf file.
If you have a working DNS entry you can ommit this field.</source>
        <translation>(Необязательно) Адрес DNS сервера для записи в файл /etc/resov.conf.
Заполните, если у Вы знаете адрес DNS сервера.</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="195"/>
        <source>A script, that should be startet before the network configuration is done.</source>
        <translation>Скрипт, запускающийся перед конфигурацией сети.</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="198"/>
        <source>A script, that should be startet after the network configurationis done.</source>
        <translation>Скрипт, запускающийся после конфигурации сети.</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="203"/>
        <source>Channel (Standard = auto)</source>
        <translation>Канал (Стандарт = auto)</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="212"/>
        <source>Bit Rate (Standard = auto)</source>
        <translation>Скорость (Стандарт = auto)</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="228"/>
        <source>Select a script to run</source>
        <translation>Выберите скрипт для запуска</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="230"/>
        <source>save as</source>
        <translation>сохранить как</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="232"/>
        <source>Save the actual configuration</source>
        <translation>Сохранить текущую конфигурацию</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="234"/>
        <source>close</source>
        <translation>закрыть</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="236"/>
        <source>close this dialog window without doing anything</source>
        <translation>закрыть этот диалог без сохранения</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="238"/>
        <source>Activate</source>
        <translation>Активировать</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="240"/>
        <source>Try to activate the new network configuration</source>
        <translation>Попытаться активировать новую конфигурацию сети</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="246"/>
        <source>Link Quality</source>
        <translation>Качество</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="255"/>
        <source>Disable all remaining interfaces</source>
        <translation>Отключить другие интерфейсы</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="258"/>
        <source>Shut down all remaining interfaces.</source>
        <translation>Выключить все оставшиеся интерфейсы.</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="376"/>
        <source>Question</source>
        <translation>Вопрос</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="376"/>
        <source>No network essid found. Do you want to enter a network essid manually</source>
        <translation>Беспроводные сети не найдены. Вы можете ввести имя сети вручную.</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="427"/>
        <source>Enter the ESSID of your network:</source>
        <translation>Введите имя Вашей сети:</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="698"/>
        <source>Info</source>
        <translation>В</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="410"/>
        <source>There was at least one hidden cell found!</source>
        <translation>Были найдены скрытые сети!</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="663"/>
        <source>Save as</source>
        <translation>Сохранить как</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="663"/>
        <source>Save configuration as (press Enter to save it with its actual name):</source>
        <translation>Сохранить конфигурацию как (нажмите Enter для сохранения под текущим именем):</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="698"/>
        <source>Configuration for </source>
        <translation>Конфигурация для</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="698"/>
        <source> saved!</source>
        <translation>Успешно сохранено!</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="1117"/>
        <source>WARNING</source>
        <translation>ПРЕДУПРЕЖДЕНИЕ</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="700"/>
        <source>Couldn&apos;t save the configuration. Unknown Error!</source>
        <translation>Невозможно сохранить конфигурацию. Неизвестная ошибка!</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="726"/>
        <source>wpa_supplicant not found. No WPA encryption available
</source>
        <translation>Не найден wpa_supplicant. Протокол WPA недоступен.
</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="723"/>
        <source>wpa_supplicant found : </source>
        <translation>wpa_supplicant найден: </translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="754"/>
        <source>iwlist found : </source>
        <translation>iwlist найден: </translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="788"/>
        <source>iwconfig not found. No configuration of wlan possible.
</source>
        <translation>Не найден iwconfig. Невозможно настроить интерфейс wlan.
</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="785"/>
        <source>iwconfig found : </source>
        <translation>iwconfig найден: </translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="831"/>
        <source>dhcpcd not found. No dhcp configuration possible. Static IP only
</source>
        <translation>Не найден dhcpcd. Настройка динамического IP адреса невозможна. Только статический IP адрес.
</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="827"/>
        <source>dhcpcd found : </source>
        <translation>dhcpcd найден: </translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="833"/>
        <source>not found</source>
        <translation>не найден</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="833"/>
        <source>Warning</source>
        <translation>Предупреждение</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="1111"/>
        <source>invalid Key. Can not create config file</source>
        <translation>Неправильный ключ. Невозможно создать конфигурационный фал.</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="1117"/>
        <source>Do you realy want to remove the config-file for </source>
        <translation>Вы действительно хотите удалить конфигурационный файл для </translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="1133"/>
        <source>Select a File</source>
        <translation>Выберите файл</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="1128"/>
        <source>Select the pre config script.</source>
        <translation>Выберите пре-конфигурационный скрипт</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="1133"/>
        <source>Select the post config script.</source>
        <translation>Выберите пост-конфигурационный скрипт</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="1179"/>
        <source>Signal Qual. : bad</source>
        <translation>Сигнал: плохой</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="1183"/>
        <source>Signal Qual. : medium</source>
        <translation>Сигнал: средний</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="1187"/>
        <source>Signal Qual. : good</source>
        <translation>Сигнал: хороший</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="1191"/>
        <source>Signal Qual. : excellent</source>
        <translation>Сигнал: отличный</translation>
    </message>
</context>
<context>
    <name>wifiStartup</name>
    <message>
        <location filename="../src/wifistartup.cpp" line="28"/>
        <source>WiFi-Setup startup</source>
        <translation>Настройка беспроводной сети</translation>
    </message>
    <message>
        <location filename="../src/wifistartup.cpp" line="30"/>
        <source>Start WiFi-Setup</source>
        <translation>Запуск настройки Wi-Fi</translation>
    </message>
    <message>
        <location filename="../src/wifistartup.cpp" line="38"/>
        <source>Messages produced by the startup script</source>
        <translation>Сообщения скрипта настройки беспроводной сети</translation>
    </message>
    <message>
        <location filename="../src/wifistartup.cpp" line="43"/>
        <source>done</source>
        <translation>Готово</translation>
    </message>
    <message>
        <location filename="../src/wifistartup.cpp" line="45"/>
        <source>Close this window.</source>
        <translation>Закончить и закрыть это окно</translation>
    </message>
    <message>
        <location filename="../src/wifistartup.cpp" line="47"/>
        <source>export Script</source>
        <translation>Экспорт скрипта</translation>
    </message>
    <message>
        <location filename="../src/wifistartup.cpp" line="49"/>
        <source>Export the startup script for external use!</source>
        <translation>Экспорт скрипта настройки Wi-Fi для дополнительного использования</translation>
    </message>
    <message>
        <location filename="../src/wifistartup.cpp" line="51"/>
        <source>Start Script</source>
        <translation>Запуск скрипта</translation>
    </message>
    <message>
        <location filename="../src/wifistartup.cpp" line="53"/>
        <source>Start the setup script to set up the wifi interface</source>
        <translation>Запуск скрипта настройки Wi-Fi</translation>
    </message>
    <message>
        <location filename="../src/wifistartup.cpp" line="83"/>
        <source>Starting Script: </source>
        <translation>Запуск скрипта: </translation>
    </message>
    <message>
        <location filename="../src/wifistartup.cpp" line="102"/>
        <source>
DONE!</source>
        <translation>ГОТОВО!</translation>
    </message>
    <message>
        <location filename="../src/wifistartup.cpp" line="114"/>
        <source>get existing Directory</source>
        <translation>использовать существующую директорию</translation>
    </message>
    <message>
        <location filename="../src/wifistartup.cpp" line="114"/>
        <source>Choose a folder where to save</source>
        <translation>Выберите папку для сохранения</translation>
    </message>
    <message>
        <location filename="../src/wifistartup.cpp" line="117"/>
        <source>Info</source>
        <translation>В</translation>
    </message>
    <message>
        <location filename="../src/wifistartup.cpp" line="117"/>
        <source>Script </source>
        <translation>Скрипт</translation>
    </message>
    <message>
        <location filename="../src/wifistartup.cpp" line="117"/>
        <source> saved at </source>
        <translation>сохранен как</translation>
    </message>
    <message>
        <location filename="../src/wifistartup.cpp" line="117"/>
        <source> failed!</source>
        <translation>неудалось!</translation>
    </message>
</context>
<context>
    <name>wikiLookup</name>
    <message>
        <location filename="../src/wikilookup.cpp" line="40"/>
        <source>lookup</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/wikilookup.cpp" line="42"/>
        <source>cancel installation</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/wikilookup.cpp" line="45"/>
        <source>continue installation</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/wikilookup.cpp" line="48"/>
        <source>Search : </source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/wikilookup.cpp" line="108"/>
        <source>Sorry. No information for your hardware found in the ndiswrapper wiki!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/wikilookup.cpp" line="142"/>
        <source>Sorry. No information found for the keyword you enterd!</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/wikilookup.cpp" line="144"/>
        <source>
To continue the installation you must find the appropriate .inf-File. Maybe the information above from the ndiswrapper wiki gives you some help. The driver may be packed in an archiv file (*.cab, *.zip or even *.exe). Search for this files and try cabextrac for *.cab, unzip for *.zip and unshield for .exe files.
Good luck.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/wikilookup.cpp" line="42"/>
        <source>close window</source>
        <translation type="unfinished"></translation>
    </message>
</context>
</TS>
