$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- extensions/shell/app/shell_main_delegate.cc.orig	2024-11-14 01:04:09.342611300 +0000
+++ extensions/shell/app/shell_main_delegate.cc
@@ -43,7 +43,7 @@
 #if BUILDFLAG(IS_WIN)
 #include "base/base_paths_win.h"
 #include "base/process/process_info.h"
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "base/nix/xdg_util.h"
 #elif BUILDFLAG(IS_MAC)
 #include "base/base_paths_mac.h"
@@ -63,7 +63,7 @@ base::FilePath GetDataPath() {
   }
 
   base::FilePath data_dir;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   std::unique_ptr<base::Environment> env(base::Environment::Create());
   data_dir = base::nix::GetXDGDirectory(
       env.get(), base::nix::kXdgConfigHomeEnvVar, base::nix::kDotConfigDir);
