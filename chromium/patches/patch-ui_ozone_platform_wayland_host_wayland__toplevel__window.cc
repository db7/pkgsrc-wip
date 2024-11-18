$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/ozone/platform/wayland/host/wayland_toplevel_window.cc.orig	2024-11-14 01:04:23.967757700 +0000
+++ ui/ozone/platform/wayland/host/wayland_toplevel_window.cc
@@ -629,7 +629,7 @@ void WaylandToplevelWindow::HandleToplev
   const bool did_active_change = is_active_ != window_states.is_activated;
   is_active_ = window_states.is_activated;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // The tiled state affects the window geometry, so apply it here.
   if (window_states.tiled_edges != tiled_state_) {
     // This configure changes the decoration insets.  We should adjust the
