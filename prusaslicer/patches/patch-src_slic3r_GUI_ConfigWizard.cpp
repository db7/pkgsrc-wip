$NetBSD$

Treat NetBSD like Linux.

--- src/slic3r/GUI/ConfigWizard.cpp.orig	2024-04-05 09:25:31.000000000 +0000
+++ src/slic3r/GUI/ConfigWizard.cpp
@@ -69,7 +69,7 @@
 #include "slic3r/GUI/I18N.hpp"
 #include "slic3r/Config/Version.hpp"
 
-#if defined(__linux__) && defined(__WXGTK3__)
+#if (defined(__linux__) || defined(__NetBSD__)) && defined(__WXGTK3__)
 #define wxLinux_gtk3 true
 #else
 #define wxLinux_gtk3 false
@@ -596,7 +596,7 @@ void PageWelcome::set_run_reason(ConfigW
     const bool data_empty = run_reason == ConfigWizard::RR_DATA_EMPTY;
     welcome_text->Show(data_empty);
     cbox_reset->Show(!data_empty);
-#if defined(__linux__) && defined(SLIC3R_DESKTOP_INTEGRATION)
+#if (defined(__linux__) || defined(__NetBSD__)) && defined(SLIC3R_DESKTOP_INTEGRATION)
     if (!DesktopIntegrationDialog::is_integrated())
         cbox_integrate->Show(true);
     else
@@ -1518,7 +1518,7 @@ PageDownloader::PageDownloader(ConfigWiz
         ));
     }
 
-#if defined(__linux__) && defined(SLIC3R_DESKTOP_INTEGRATION) 
+#if (defined(__linux__) || defined(__NetBSD__)) && defined(SLIC3R_DESKTOP_INTEGRATION) 
     append_text(wxString::Format(_L(
         "On Linux systems the process of registration also creates desktop integration files for this version of application."
     )));
@@ -1582,7 +1582,7 @@ bool DownloaderUtils::Worker::perform_re
 #elif __APPLE__
     // Apple registers for custom url in info.plist thus it has to be already registered since build.
     // The url will always trigger opening of prusaslicer and we have to check that user has allowed it. (GUI_App::MacOpenURL is the triggered method)
-#elif defined(__linux__) && defined(SLIC3R_DESKTOP_INTEGRATION) 
+#elif (defined(__linux__) || defined(__NetBSD__)) && defined(SLIC3R_DESKTOP_INTEGRATION) 
     // the performation should be called later during desktop integration
     perform_registration_linux = true;
 #endif
