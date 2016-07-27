$NetBSD$

--- wordfuncs.c.orig	2016-07-27 20:00:36.504275890 +0000
+++ wordfuncs.c
@@ -14,9 +14,9 @@ char wordfuncs_RCSid[] = "Revision: 1.2 
 
 #include "agm.h"
 
-int contains (word, subword, length)
-    char *word, *subword;
-    unsigned int *length;
+#include <stdlib.h>
+
+int contains (char *word, char *subword, unsigned int *length)
 {
   char copyword[WORDLEN];
   char *cpos, *sloop;
@@ -36,8 +36,7 @@ int contains (word, subword, length)
   return TRUE;
 }
 
-int eliminate (word, subword, remains)
-    char *word, *subword, *remains;
+int eliminate (char *word, char *subword, char *remains)
 {
   char copyword[WORDLEN];
   char *remloop = remains, *copyloop = copyword;
@@ -55,8 +54,8 @@ int eliminate (word, subword, remains)
   *remloop = '\0';
 }
 
-minus_process (word, command)
-    char *word, *command;
+void
+minus_process (char *word, char *command)
 {
   char *minus_pos, copy[WORDLEN];
   unsigned int dummy;
@@ -78,9 +77,7 @@ minus_process (word, command)
   }
 }
 
-void copysmall (s1, s2)
-  char
-      *s1, *s2;
+void copysmall (char *s1, char *s2)
 {
   while (*s2 != '\0') {
     if (*s2 >= 'A' && *s2 <= 'Z') {
