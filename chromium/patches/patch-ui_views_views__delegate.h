$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/views/views_delegate.h.orig	2024-08-21 22:46:46.817352000 +0000
+++ ui/views/views_delegate.h
@@ -146,7 +146,7 @@ class VIEWS_EXPORT ViewsDelegate {
   // environment.
   virtual bool IsWindowInMetro(gfx::NativeWindow window) const;
 #elif BUILDFLAG(ENABLE_DESKTOP_AURA) && \
-    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS))
+    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD))
   virtual gfx::ImageSkia* GetDefaultWindowIcon() const;
 #endif
 
