$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- gpu/command_buffer/service/shared_context_state.h.orig	2024-10-26 07:00:17.877462400 +0000
+++ gpu/command_buffer/service/shared_context_state.h
@@ -222,7 +222,7 @@ class GPU_GLES2_EXPORT SharedContextStat
     return &memory_type_tracker_;
   }
 #if BUILDFLAG(ENABLE_VULKAN) && \
-    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_WIN))
+    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD))
   ExternalSemaphorePool* external_semaphore_pool() {
     return external_semaphore_pool_.get();
   }
@@ -429,7 +429,7 @@ class GPU_GLES2_EXPORT SharedContextStat
   bool disable_check_reset_status_throttling_for_test_ = false;
 
 #if BUILDFLAG(ENABLE_VULKAN) && \
-    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_WIN))
+    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD))
   std::unique_ptr<ExternalSemaphorePool> external_semaphore_pool_;
 #endif
 
