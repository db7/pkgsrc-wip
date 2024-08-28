$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- content/browser/renderer_host/render_widget_host_view_aura.cc.orig	2024-08-21 22:46:18.270422700 +0000
+++ content/browser/renderer_host/render_widget_host_view_aura.cc
@@ -120,7 +120,7 @@
 #include "ui/gfx/gdi_util.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "content/browser/accessibility/browser_accessibility_auralinux.h"
 #include "ui/base/ime/linux/text_edit_command_auralinux.h"
 #include "ui/base/ime/text_input_flags.h"
@@ -479,7 +479,7 @@ gfx::NativeViewAccessible RenderWidgetHo
     return ToBrowserAccessibilityWin(manager->GetBrowserAccessibilityRoot())
         ->GetCOM();
 
-#elif BUILDFLAG(IS_LINUX)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   BrowserAccessibilityManager* manager =
       host()->GetOrCreateRootBrowserAccessibilityManager();
   if (manager && manager->GetBrowserAccessibilityRoot())
@@ -1733,7 +1733,7 @@ bool RenderWidgetHostViewAura::ShouldDoL
   return host() && host()->delegate() && host()->delegate()->ShouldDoLearning();
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 bool RenderWidgetHostViewAura::SetCompositionFromExistingText(
     const gfx::Range& range,
     const std::vector<ui::ImeTextSpan>& ui_ime_text_spans) {
@@ -2561,7 +2561,7 @@ bool RenderWidgetHostViewAura::NeedsInpu
 }
 
 bool RenderWidgetHostViewAura::NeedsMouseCapture() {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD)
   return NeedsInputGrab();
 #else
   return false;
@@ -2745,7 +2745,7 @@ void RenderWidgetHostViewAura::ForwardKe
   if (!target_host)
     return;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   auto* linux_ui = ui::LinuxUi::instance();
   std::vector<ui::TextEditCommandAuraLinux> commands;
   if (!event.skip_if_unhandled && linux_ui && event.os_event &&
