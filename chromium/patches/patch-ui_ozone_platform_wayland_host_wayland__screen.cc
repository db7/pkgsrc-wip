$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/ozone/platform/wayland/host/wayland_screen.cc.orig	2024-10-26 07:01:27.354894400 +0000
+++ ui/ozone/platform/wayland/host/wayland_screen.cc
@@ -46,7 +46,7 @@
 #include "ui/ozone/platform/wayland/host/org_gnome_mutter_idle_monitor.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/linux/linux_ui.h"
 #endif
 
@@ -133,7 +133,7 @@ WaylandScreen::WaylandScreen(WaylandConn
   tablet_state_ = connection_->GetTabletState();
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (auto* linux_ui = ui::LinuxUi::instance()) {
     OnDeviceScaleFactorChanged();
     display_scale_factor_observer_.Observe(linux_ui);
@@ -606,7 +606,7 @@ bool WaylandScreen::VerifyOutputStateCon
   return true;
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void WaylandScreen::OnDeviceScaleFactorChanged() {
   if (const auto* linux_ui = ui::LinuxUi::instance()) {
     const float new_font_scale = linux_ui->display_config().font_scale;
