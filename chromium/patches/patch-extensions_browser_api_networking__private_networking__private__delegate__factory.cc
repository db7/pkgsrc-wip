$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- extensions/browser/api/networking_private/networking_private_delegate_factory.cc.orig	2024-11-14 01:04:09.263610600 +0000
+++ extensions/browser/api/networking_private/networking_private_delegate_factory.cc
@@ -12,7 +12,7 @@
 
 #if BUILDFLAG(IS_CHROMEOS)
 #include "extensions/browser/api/networking_private/networking_private_chromeos.h"
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "extensions/browser/api/networking_private/networking_private_linux.h"
 #elif BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
 #include "components/wifi/wifi_service.h"
@@ -63,7 +63,7 @@ NetworkingPrivateDelegateFactory::BuildS
   std::unique_ptr<NetworkingPrivateDelegate> delegate;
 #if BUILDFLAG(IS_CHROMEOS)
   delegate = std::make_unique<NetworkingPrivateChromeOS>(browser_context);
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   delegate = std::make_unique<NetworkingPrivateLinux>();
 #elif BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
   std::unique_ptr<wifi::WiFiService> wifi_service(wifi::WiFiService::Create());
