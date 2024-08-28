$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/webrtc/rtc_base/net_test_helpers.cc.orig	2024-08-21 22:48:15.273425800 +0000
+++ third_party/webrtc/rtc_base/net_test_helpers.cc
@@ -21,6 +21,7 @@
 #endif
 #if defined(WEBRTC_POSIX) && !defined(__native_client__)
 #include <arpa/inet.h>
+#include <sys/socket.h>
 #if defined(WEBRTC_ANDROID)
 #include "rtc_base/ifaddrs_android.h"
 #else
