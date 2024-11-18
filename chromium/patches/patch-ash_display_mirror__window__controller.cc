$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ash/display/mirror_window_controller.cc.orig	2024-11-14 01:04:01.235530400 +0000
+++ ash/display/mirror_window_controller.cc
@@ -295,7 +295,11 @@ void MirrorWindowController::UpdateWindo
       if (!base::Contains(display_info_list, iter->first,
                           &display::ManagedDisplayInfo::id)) {
         CloseAndDeleteHost(iter->second, true);
+#if defined(__llvm__)
+        mirroring_host_info_map_.erase(iter++);
+#else
         iter = mirroring_host_info_map_.erase(iter);
+#endif
       } else {
         ++iter;
       }
