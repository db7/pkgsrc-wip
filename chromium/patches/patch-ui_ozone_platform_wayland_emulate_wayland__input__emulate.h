$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/ozone/platform/wayland/emulate/wayland_input_emulate.h.orig	2024-08-21 22:46:46.600329900 +0000
+++ ui/ozone/platform/wayland/emulate/wayland_input_emulate.h
@@ -68,7 +68,7 @@ class WaylandInputEmulate : public wl::W
                             uint32_t request_id);
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void ForceUseScreenCoordinatesOnce();
 #endif
 
