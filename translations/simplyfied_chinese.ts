<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE TS><TS version="1.1">
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
        <translation type="unfinished">警告</translation>
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
        <translation type="unfinished">注意</translation>
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
        <translation>KNDISWrapper 能够帮助您用 ndiswrapper 建立您的无线网络。

安装驱动按钮可用来为 ndiswrapper 支持的无线设备安装一个新的驱动。以实现这样，您得要验证合适的“.inf”文件。有时候您可以在随硬件附送的驱动光盘中找到这个文件。在一些场合这个文件存储在一个“.cab”文件。这是一个 Windows 归档文件并可以用“cabextract”解压缩。如果附送的驱动只有一个“.exe”安装文件，您就只好在 Windows 下安装这个驱动并在 Windows 目录中查找驱动。

删除驱动按钮用来删除不工作或不再使用的 Windows 驱动。
驱动文件将会备份以在需要时能进行还原。

用重载列表按钮可使驱动列表再次装入。更改(例如，安装的硬件)不会自动探测。

用还原驱动按钮，您可以重新安装一个先前通过删除按钮删除的驱动。

配置网络可调出网络配置对话框。在此您能建立与您在列表中所选驱动有关的网卡。

用退出按钮便能退出此应用程序。</translation>
    </message>
    <message>
        <location filename="../src/kndiswrapper.cpp" line="82"/>
        <source>Add Driver</source>
        <translation>添加驱动</translation>
    </message>
    <message>
        <location filename="../src/kndiswrapper.cpp" line="305"/>
        <source>Remove Driver</source>
        <translation>删除驱动</translation>
    </message>
    <message>
        <location filename="../src/kndiswrapper.cpp" line="113"/>
        <source>Reload List</source>
        <translation>重载列表</translation>
    </message>
    <message>
        <location filename="../src/kndiswrapper.cpp" line="87"/>
        <source>Module Check</source>
        <translation>模块检查</translation>
    </message>
    <message>
        <location filename="../src/kndiswrapper.cpp" line="88"/>
        <source>Info dmesg</source>
        <translation>信息 demsg</translation>
    </message>
    <message>
        <location filename="../src/kndiswrapper.cpp" line="122"/>
        <source>Config Network</source>
        <translation>配置网络</translation>
    </message>
    <message>
        <location filename="../src/kndiswrapper.cpp" line="100"/>
        <source>Right-Click for more options</source>
        <translation>右键点击以使用更多选项</translation>
    </message>
    <message>
        <location filename="../src/kndiswrapper.cpp" line="333"/>
        <source>Install Driver</source>
        <translation>安装驱动</translation>
    </message>
    <message>
        <location filename="../src/kndiswrapper.cpp" line="107"/>
        <source>Install a new driver. Therefor locate the appropriate .inf file.</source>
        <translation>安装新驱动。然后定位合适的 .inf 文件。</translation>
    </message>
    <message>
        <location filename="../src/kndiswrapper.cpp" line="111"/>
        <source>Removes the selected driver in the list.</source>
        <translation>删除列表中所选驱动。</translation>
    </message>
    <message>
        <location filename="../src/kndiswrapper.cpp" line="115"/>
        <source>Reload the content of the list</source>
        <translation>重新装入列表内容</translation>
    </message>
    <message>
        <location filename="../src/kndiswrapper.cpp" line="117"/>
        <source>Restore Driver</source>
        <translation>还原驱动</translation>
    </message>
    <message>
        <location filename="../src/kndiswrapper.cpp" line="119"/>
        <source>Restores a removed driver.</source>
        <translation>还原已删除的驱动。</translation>
    </message>
    <message>
        <location filename="../src/kndiswrapper.cpp" line="124"/>
        <source>Start&apos;s the network configuration dialog</source>
        <translation>启动网络配置对话框</translation>
    </message>
    <message>
        <location filename="../src/kndiswrapper.cpp" line="127"/>
        <source>Quit</source>
        <translation>退出</translation>
    </message>
    <message>
        <location filename="../src/kndiswrapper.cpp" line="129"/>
        <source>Quit the application</source>
        <translation>退出应用程序</translation>
    </message>
    <message>
        <location filename="../src/kndiswrapper.cpp" line="305"/>
        <source>Are you sure you want to remove the driver : </source>
        <translation>您确定您想要删除驱动：</translation>
    </message>
    <message>
        <location filename="../src/kndiswrapper.cpp" line="333"/>
        <source>The driver has been succesfully installed</source>
        <translation>驱动已成功安装</translation>
    </message>
    <message>
        <location filename="../src/kndiswrapper.cpp" line="652"/>
        <source>Warning</source>
        <translation>警告</translation>
    </message>
    <message>
        <location filename="../src/kndiswrapper.cpp" line="336"/>
        <source>The driver is already installed</source>
        <translation>驱动已经安装过</translation>
    </message>
    <message>
        <location filename="../src/kndiswrapper.cpp" line="339"/>
        <source>Error</source>
        <translation>错误</translation>
    </message>
    <message>
        <location filename="../src/kndiswrapper.cpp" line="339"/>
        <source>Unable to install the driver!

</source>
        <translation>无法安装驱动！

</translation>
    </message>
    <message>
        <location filename="../src/kndiswrapper.cpp" line="341"/>
        <source>Unkown outcome!
</source>
        <translation>未知输出！
</translation>
    </message>
    <message>
        <location filename="../src/kndiswrapper.cpp" line="345"/>
        <source>Writeing of configuration failed!</source>
        <translation>配置写入失败！</translation>
    </message>
    <message>
        <location filename="../src/kndiswrapper.cpp" line="346"/>
        <source>Removing of ndiswrapper module failed!</source>
        <translation>删除 ndiswrapper 模块失败！</translation>
    </message>
    <message>
        <location filename="../src/kndiswrapper.cpp" line="347"/>
        <source>Loading of ndiswrapper module failed!</source>
        <translation>装入 ndiswrapper 模块失败！</translation>
    </message>
    <message>
        <location filename="../src/kndiswrapper.cpp" line="388"/>
        <source>INF-Files (*.inf)</source>
        <translation>INF 文件(*.inf)</translation>
    </message>
    <message>
        <location filename="../src/kndiswrapper.cpp" line="356"/>
        <source>Removed Drivers</source>
        <translation>已删除驱动</translation>
    </message>
    <message>
        <location filename="../src/kndiswrapper.cpp" line="388"/>
        <source>Select a File</source>
        <translation>选择一个文件</translation>
    </message>
    <message>
        <location filename="../src/kndiswrapper.cpp" line="388"/>
        <source>New Driver</source>
        <translation>新驱动</translation>
    </message>
    <message>
        <location filename="../src/kndiswrapper.cpp" line="412"/>
        <source>Removing Driver</source>
        <translation>删除驱动</translation>
    </message>
    <message>
        <location filename="../src/kndiswrapper.cpp" line="412"/>
        <source>The driver has been succesfully removed</source>
        <translation>驱动已成功删除</translation>
    </message>
    <message>
        <location filename="../src/kndiswrapper.cpp" line="414"/>
        <source>Unable to remove the driver!
</source>
        <translation>无法删除驱动！
</translation>
    </message>
    <message>
        <location filename="../src/kndiswrapper.cpp" line="442"/>
        <source>Fatal Error</source>
        <translation>致命错误</translation>
    </message>
    <message>
        <location filename="../src/kndiswrapper.cpp" line="442"/>
        <source>ndiswrapper not found.
Please install ndiswrapper before you proceed.
Program aborting!</source>
        <translation>未找到 ndiswrapper。
请在您进行前安装 ndiswrapper。
程序终止！</translation>
    </message>
    <message>
        <location filename="../src/kndiswrapper.cpp" line="515"/>
        <source>Attention</source>
        <translation>注意</translation>
    </message>
    <message>
        <location filename="../src/kndiswrapper.cpp" line="468"/>
        <source>There is no alternativ driver for </source>
        <translation>没有可选的驱动用于 </translation>
    </message>
    <message>
        <location filename="../src/kndiswrapper.cpp" line="481"/>
        <source>A alternativ driver is loaded by the kernel. This may
prevent ndiswrapper from working properly. </source>
        <translation>可选驱动已由内核装入。这样可能
阻止 ndiswrapper 正常工作。</translation>
    </message>
    <message>
        <location filename="../src/kndiswrapper.cpp" line="482"/>
        <source>We have
to remove the loaded kernel module and blacklist the
kernel module so it</source>
        <translation>我们必须
删除已装入的内核模块并对
内核模块列入黑名单</translation>
    </message>
    <message>
        <location filename="../src/kndiswrapper.cpp" line="483"/>
        <source> will not be loaded by the kernel again.

Shall I try to fix the problem for you?</source>
        <translation>这样就不会再次由内核装入了。

我是否要为您修正这个问题？</translation>
    </message>
    <message>
        <location filename="../src/kndiswrapper.cpp" line="497"/>
        <source>
Hints:
- I will do a : rmmod </source>
        <translation>
提示：
- 我将执行：rmmod </translation>
    </message>
    <message>
        <location filename="../src/kndiswrapper.cpp" line="497"/>
        <source>
- enter the name of the module into /etc/modprobe.d/blacklist
- and into /etc/modprobe.conf

</source>
        <translation>
- 向 /etc/modprobe.d/blacklist
- 以及 /etc/modprobe.conf 输入模块名称

</translation>
    </message>
    <message>
        <location filename="../src/kndiswrapper.cpp" line="515"/>
        <source>No conflicting kernel modules are loaded!
&gt;&gt;&gt;&gt;&gt; erverything is fine &lt;&lt;&lt;&lt;&lt;</source>
        <translation>没有装入冲突的内核模块！
&gt;&gt;&gt;&gt;&gt; 一切正常 &lt;&lt;&lt;&lt;&lt;</translation>
    </message>
    <message>
        <location filename="../src/kndiswrapper.cpp" line="538"/>
        <source>WARNING</source>
        <translation>警告</translation>
    </message>
    <message>
        <location filename="../src/kndiswrapper.cpp" line="538"/>
        <source>The ndiswrapper module is not loaded.
ndiswrapper will not be able to identify any hardware.
Shall I load the kernel module for you?</source>
        <translation>没有装入 ndiswrapper 模块。
ndiswrapper 将无法验证任何硬件。
我是否要为您装入内核模块？</translation>
    </message>
    <message>
        <location filename="../src/kndiswrapper.cpp" line="541"/>
        <source>Loading of the kernel module (ndiswrapper) failed!</source>
        <translation>装入内核模块(ndiswrapper)失败！</translation>
    </message>
    <message>
        <location filename="../src/kndiswrapper.cpp" line="598"/>
        <source>dmesg-Info</source>
        <translation>dmesg 信息</translation>
    </message>
    <message>
        <location filename="../src/kndiswrapper.cpp" line="652"/>
        <source>Can&apos;t start the network configuration! No interface found!</source>
        <translation>无法启动网络配置！没有找到网卡！</translation>
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
        <translation>在此您可以为您的无线网卡建立多种参数

操作模式可设为用于点对点网络无接入点的 Ad-hoc 或用于互联网有接入点的 Managed。

指派您网络的 essid(通过扫描或手动输入)。此信息需要用于确保您的计算机是网络单元的一部分。
如果您使用 managed 网络并不使用 WPA 作为认证，您可以空出这个字段。在这种场合下，wifi 适配器会使用最佳信号质量的接入点

在网络中您需要指定认证模式。这里您可以选择 WEP 和 WPA。WEP(Wired Equivalent Privacy)是种用于带有可选认证加密的系统。通常在使用 WEP 时，模式 WEP-Open 是合适的(无认证)。

WEP 常被认为是不安全的。这样，WPA(Wifi Protected Access)实现了。但并不是所有硬件都支持 WPA。WPA 只能用在 Managed 模式。

您可以以十六进制，ASCII 或密码输入密钥。
如果您使用 WEB 作为认证模式，您得输入 10 位十六进制值用做 64 比特密钥，26 位十六进制值用做 128 比特密钥，32 位十六进制值用做 156 比特密钥以及 58 位用做 256 比特密钥。您也可以输入 5 个字符用做 64-bit 密钥，13 个字符用做 128 比特密钥，16 个字符用做 156 比特密钥以及 29 个字符用做 256 比特密钥。但请留意，不是所有硬件都支持 256 比特的密钥。

如果您使用 WPA，您得以十六进制输入密钥。这样，您就拥有了一个 64 位十六进制密钥或您也可以输入密码(8 - 63 个字符)</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="50"/>
        <source>Device : </source>
        <translation>设备：</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="71"/>
        <source>Read this for further information about how to setup your wireless lan</source>
        <translation>阅读它以获取关于如何建立您的无线网络更多信息</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="73"/>
        <source>Profile : </source>
        <translation>配置：</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="80"/>
        <source>If multiple configurations are found, you can select the active configuration</source>
        <translation>如果找到多个配置，您可以选择激活配置</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="84"/>
        <source>Removes the actual configuration file</source>
        <translation>删除实际配置文件</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="86"/>
        <source>Key-Format</source>
        <translation>密钥格式</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="87"/>
        <source>Select the way you want to enter your key</source>
        <translation>选择您想要输入您密钥的方式</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="97"/>
        <source>Config</source>
        <translation>配置</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="99"/>
        <source>Select whether you want to config interface with a static IP or via DHCP</source>
        <translation>选择您想要用静态 IP 或通过 DHCP 配置网卡</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="100"/>
        <source>Static IP</source>
        <translation>静态 IP</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="101"/>
        <source>DHCP</source>
        <translation>DHCP</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="110"/>
        <source>Shows the number of character and whether the key is valid (green) or not (red)</source>
        <translation>显示字符数和密钥是有效(绿)还是无效(红)</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="114"/>
        <source>Enter the hex-key or passphrase</source>
        <translation>输入十六进制密钥或密码</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="117"/>
        <source>Mode of Operation</source>
        <translation>操作模式</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="427"/>
        <source>ESSID</source>
        <translation>ESSID</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="119"/>
        <source>Authentication</source>
        <translation>认证</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="121"/>
        <source>Select a network or enter the ESSID manually</source>
        <translation>选择一个网络或手动输入 ESSID</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="123"/>
        <source>Select which encryption mode you want to use</source>
        <translation>选择您想要使用的加密模式</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="140"/>
        <source>ESSID-Scan</source>
        <translation>ESSID 扫描</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="142"/>
        <source>Scan for available networks</source>
        <translation>扫描可用网络</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="146"/>
        <source>Enter the name of your network (ESSID) manually</source>
        <translation>手动输入您网络(ESSID)的名称</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="155"/>
        <source>Required Programms:

</source>
        <translation>需要程序：

</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="157"/>
        <source>IP-Addr : </source>
        <translation>IP 地址：</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="159"/>
        <source>Netmask : </source>
        <translation>掩码：</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="161"/>
        <source>Default GW (opt.) : </source>
        <translation>默认网关(可选)：</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="163"/>
        <source>DNS Entry (opt)</source>
        <translation>DNS 入口(可选)</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="167"/>
        <source>pre Conf. Script</source>
        <translation>前期配置脚本</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="169"/>
        <source>post Conf. Script</source>
        <translation>后期配置脚本</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="180"/>
        <source>Enter the static IP-Addr of the interface (192.168.2.1)</source>
        <translation>输入网卡静态 IP 地址(192.168.2.1)</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="183"/>
        <source>Enter the desired Netmask (255.255.255.0)</source>
        <translation>输入所需掩码(255.255.255.0)</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="186"/>
        <source>(Optional) The IP Address of the Gateway (e.g. DSL Route to the internet)
If you have a working default Gateway you can ommit this field</source>
        <translation>(可选)网关的 IP 地址(例如，连接到互联网的 DSL 路由器)
如果您有可工作的默认网关，您可以空掉这个字段</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="192"/>
        <source>Optional a DNS Entry for the /etc/resolv.conf file.
If you have a working DNS entry you can ommit this field.</source>
        <translation>用于 /etc/resolv.conf 文件的可选 DNS 入口。
如果您有可工作的 DNS 入口，您可以空掉这个字段。</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="195"/>
        <source>A script, that should be startet before the network configuration is done.</source>
        <translation>在网络配置完成之前启动运行的脚本。</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="198"/>
        <source>A script, that should be startet after the network configurationis done.</source>
        <translation>在网络配置完成之后启动运行的脚本。</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="228"/>
        <source>Select a script to run</source>
        <translation>选择要运行的脚本</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="230"/>
        <source>save as</source>
        <translation>另存为</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="232"/>
        <source>Save the actual configuration</source>
        <translation>保存真实配置</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="234"/>
        <source>close</source>
        <translation>关闭</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="236"/>
        <source>close this dialog window without doing anything</source>
        <translation>关闭此对话框窗口而不进行任何操作</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="238"/>
        <source>Activate</source>
        <translation>激活</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="240"/>
        <source>Try to activate the new network configuration</source>
        <translation>尝试激活新网络配置</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="376"/>
        <source>Question</source>
        <translation>问题</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="376"/>
        <source>No network essid found. Do you want to enter a network essid manually</source>
        <translation>未找到网络 essid。您想要手动输入网络 essid</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="427"/>
        <source>Enter the ESSID of your network:</source>
        <translation>输入您网络的 ESSID：</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="698"/>
        <source>Info</source>
        <translation>信息</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="410"/>
        <source>There was at least one hidden cell found!</source>
        <translation>至少找到一个隐藏单元！</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="663"/>
        <source>Save as</source>
        <translation>另存为</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="663"/>
        <source>Save configuration as (press Enter to save it with its actual name):</source>
        <translation>配置另存为(按下回车键以用其真实名称保存)：</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="698"/>
        <source>Configuration for </source>
        <translation>配置用于 </translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="698"/>
        <source> saved!</source>
        <translation> 已保存！</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="1117"/>
        <source>WARNING</source>
        <translation>警告</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="700"/>
        <source>Couldn&apos;t save the configuration. Unknown Error!</source>
        <translation>无法保存配置。未知错误！</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="726"/>
        <source>wpa_supplicant not found. No WPA encryption available
</source>
        <translation>未找到 wpa_supplicant。无 WPA 加密可用
</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="723"/>
        <source>wpa_supplicant found : </source>
        <translation>找到 wpa_supplicant：</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="754"/>
        <source>iwlist found : </source>
        <translation>找到 iwlist：</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="788"/>
        <source>iwconfig not found. No configuration of wlan possible.
</source>
        <translation>未找到 iwconfig。无 wlan 配置可使用。
</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="785"/>
        <source>iwconfig found : </source>
        <translation>找到 iwconfig：</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="831"/>
        <source>dhcpcd not found. No dhcp configuration possible. Static IP only
</source>
        <translation>未找到 dhcpcd。无 dhcp 配置可使用。仅静态 IP
</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="827"/>
        <source>dhcpcd found : </source>
        <translation>找到 dhcpcd：</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="833"/>
        <source>not found</source>
        <translation>未找到</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="833"/>
        <source>Warning</source>
        <translation>警告</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="1111"/>
        <source>invalid Key. Can not create config file</source>
        <translation>无效密钥。无法创建配置文件</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="1117"/>
        <source>Do you realy want to remove the config-file for </source>
        <translation>您确实想要删除配置文件用于 </translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="1133"/>
        <source>Select a File</source>
        <translation>选择一个文件</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="1128"/>
        <source>Select the pre config script.</source>
        <translation>选择前期配置脚本。</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="1133"/>
        <source>Select the post config script.</source>
        <translation>选择后期配置脚本。</translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="165"/>
        <source>sec. DNS (opt)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="171"/>
        <source>Nickname</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="203"/>
        <source>Channel (Standard = auto)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="212"/>
        <source>Bit Rate (Standard = auto)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="246"/>
        <source>Link Quality</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="255"/>
        <source>Disable all remaining interfaces</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="258"/>
        <source>Shut down all remaining interfaces.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="1179"/>
        <source>Signal Qual. : bad</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="1183"/>
        <source>Signal Qual. : medium</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="1187"/>
        <source>Signal Qual. : good</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="../src/wifisetup.cpp" line="1191"/>
        <source>Signal Qual. : excellent</source>
        <translation type="unfinished"></translation>
    </message>
</context>
<context>
    <name>wifiStartup</name>
    <message>
        <location filename="../src/wifistartup.cpp" line="28"/>
        <source>WiFi-Setup startup</source>
        <translation>WiFi 建立启动</translation>
    </message>
    <message>
        <location filename="../src/wifistartup.cpp" line="30"/>
        <source>Start WiFi-Setup</source>
        <translation>启动 WiFi 建立</translation>
    </message>
    <message>
        <location filename="../src/wifistartup.cpp" line="38"/>
        <source>Messages produced by the startup script</source>
        <translation>由启动脚本产生的消息</translation>
    </message>
    <message>
        <location filename="../src/wifistartup.cpp" line="43"/>
        <source>done</source>
        <translation>完成</translation>
    </message>
    <message>
        <location filename="../src/wifistartup.cpp" line="45"/>
        <source>Close this window.</source>
        <translation>关闭此窗口。</translation>
    </message>
    <message>
        <location filename="../src/wifistartup.cpp" line="47"/>
        <source>export Script</source>
        <translation>导出脚本</translation>
    </message>
    <message>
        <location filename="../src/wifistartup.cpp" line="49"/>
        <source>Export the startup script for external use!</source>
        <translation>导出启动脚本用于外部使用！</translation>
    </message>
    <message>
        <location filename="../src/wifistartup.cpp" line="51"/>
        <source>Start Script</source>
        <translation>启动脚本</translation>
    </message>
    <message>
        <location filename="../src/wifistartup.cpp" line="53"/>
        <source>Start the setup script to set up the wifi interface</source>
        <translation>启动建立脚本以建立 wifi 网卡</translation>
    </message>
    <message>
        <location filename="../src/wifistartup.cpp" line="83"/>
        <source>Starting Script: </source>
        <translation>启动脚本：</translation>
    </message>
    <message>
        <location filename="../src/wifistartup.cpp" line="102"/>
        <source>
DONE!</source>
        <translation>
完成！</translation>
    </message>
    <message>
        <location filename="../src/wifistartup.cpp" line="114"/>
        <source>get existing Directory</source>
        <translation>获得已存在目录</translation>
    </message>
    <message>
        <location filename="../src/wifistartup.cpp" line="114"/>
        <source>Choose a folder where to save</source>
        <translation>选择用于保存的文件夹</translation>
    </message>
    <message>
        <location filename="../src/wifistartup.cpp" line="117"/>
        <source>Info</source>
        <translation>信息</translation>
    </message>
    <message>
        <location filename="../src/wifistartup.cpp" line="117"/>
        <source>Script </source>
        <translation>脚本 </translation>
    </message>
    <message>
        <location filename="../src/wifistartup.cpp" line="117"/>
        <source> saved at </source>
        <translation> 保存至 </translation>
    </message>
    <message>
        <location filename="../src/wifistartup.cpp" line="117"/>
        <source> failed!</source>
        <translation> 失败！</translation>
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
