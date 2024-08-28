$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/ui/views/frame/opaque_browser_frame_view.h.orig	2024-08-21 22:46:11.299707200 +0000
+++ chrome/browser/ui/views/frame/opaque_browser_frame_view.h
@@ -114,7 +114,7 @@ class OpaqueBrowserFrameView : public Br
   FrameButtonStyle GetFrameButtonStyle() const override;
   void UpdateWindowControlsOverlay(const gfx::Rect& bounding_rect) override;
   bool ShouldDrawRestoredFrameShadow() const override;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   bool IsTiled() const override;
 #endif
   int WebAppButtonHeight() const override;
@@ -231,7 +231,7 @@ class OpaqueBrowserFrameView : public Br
   // Background painter for the window frame.
   std::unique_ptr<views::FrameBackground> frame_background_;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   std::unique_ptr<views::MenuRunner> menu_runner_;
 #endif
 
