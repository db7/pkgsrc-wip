$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/browser/renderer_host/render_view_host_impl.cc.orig	2024-10-26 07:00:13.579851600 +0000
+++ content/browser/renderer_host/render_view_host_impl.cc
@@ -275,7 +275,7 @@ void RenderViewHostImpl::GetPlatformSpec
       display::win::ScreenWin::GetSystemMetricsInDIP(SM_CYVSCROLL);
   prefs->arrow_bitmap_width_horizontal_scroll_bar_in_dips =
       display::win::ScreenWin::GetSystemMetricsInDIP(SM_CXHSCROLL);
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   base::CommandLine* command_line = base::CommandLine::ForCurrentProcess();
   if (command_line->HasSwitch(switches::kSystemFontFamily)) {
     prefs->system_font_family_name =
