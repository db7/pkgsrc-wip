$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- base/process/process_unittest.cc.orig	2024-11-14 01:04:01.837536300 +0000
+++ base/process/process_unittest.cc
@@ -203,7 +203,7 @@ TEST_F(ProcessTest, CreationTimeOtherPro
   // was spawned and a time recorded after it was spawned. However, since the
   // base::Time and process creation clocks don't match, tolerate some error.
   constexpr base::TimeDelta kTolerance =
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
       // On Linux, process creation time is relative to boot time which has a
       // 1-second resolution. Tolerate 1 second for the imprecise boot time and
       // 100 ms for the imprecise clock.
