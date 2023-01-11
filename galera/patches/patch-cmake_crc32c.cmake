$NetBSD$

NetBSD support.

--- cmake/crc32c.cmake.orig	2022-11-02 06:09:14.000000000 +0000
+++ cmake/crc32c.cmake
@@ -42,7 +42,7 @@ int main()
 {
 #if defined(__linux__)
     (void)getauxval(AT_HWCAP);
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__NetBSD__)
     unsigned long info;
     (void)elf_aux_info(AT_HWCAP, &info, sizeof(info));
 #else
