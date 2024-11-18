$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/memory/madv_free_discardable_memory_posix.cc.orig	2024-11-14 01:04:01.814536000 +0000
+++ base/memory/madv_free_discardable_memory_posix.cc
@@ -310,6 +310,10 @@ void MadvFreeDiscardableMemoryPosix::Set
 
 bool MadvFreeDiscardableMemoryPosix::IsResident() const {
   DFAKE_SCOPED_RECURSIVE_LOCK(thread_collision_warner_);
+// XXX mincore
+#if BUILDFLAG(IS_BSD)
+  return false;
+#else
 #if BUILDFLAG(IS_APPLE)
   std::vector<char> vec(allocated_pages_);
 #else
@@ -325,6 +329,7 @@ bool MadvFreeDiscardableMemoryPosix::IsR
       return false;
   }
   return true;
+#endif
 }
 
 bool MadvFreeDiscardableMemoryPosix::IsDiscarded() const {
