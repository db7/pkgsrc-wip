$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- chrome/browser/metrics/power/process_metrics_recorder_util.cc.orig	2024-11-14 01:04:03.700555000 +0000
+++ chrome/browser/metrics/power/process_metrics_recorder_util.cc
@@ -65,7 +65,7 @@ void RecordProcessHistograms(const char*
                              const ProcessMonitor::Metrics& metrics) {
   RecordAverageCPUUsage(histogram_suffix, metrics.cpu_usage);
 #if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_AIX)
+    BUILDFLAG(IS_AIX) || BUILDFLAG(IS_BSD)
   base::UmaHistogramCounts10000(
       base::StrCat({"PerformanceMonitor.IdleWakeups2.", histogram_suffix}),
       metrics.idle_wakeups);
