$NetBSD$

Add an i586 / pentium variant, in an effort to support AMD Geode etc.

--- compiler/rustc_target/src/speci586_unknown_netbsd.rs.orig	2021-04-11 00:12:43.084770395 +0200
+++ compiler/rustc_target/src/spec/i586_unknown_netbsd.rs	2021-04-11 00:15:29.313073646 +0200
@@ -0,0 +1,20 @@
+use crate::spec::{LinkerFlavor, StackProbeType, Target, TargetOptions};
+
+pub fn target() -> Target {
+    let mut base = super::netbsd_base::opts();
+    base.cpu = "pentium".to_string();
+    base.max_atomic_width = Some(64);
+    base.pre_link_args.get_mut(&LinkerFlavor::Gcc).unwrap().push("-m32".to_string());
+    // don't use probe-stack=inline-asm until rust-lang/rust#83139 is resolved.
+    base.stack_probes = StackProbeType::Call;
+
+    Target {
+        llvm_target: "i586-unknown-netbsdelf".to_string(),
+        pointer_width: 32,
+        data_layout: "e-m:e-p:32:32-p270:32:32-p271:32:32-p272:64:64-\
+            f64:32:64-f80:32-n8:16:32-S128"
+            .to_string(),
+        arch: "x86".to_string(),
+        options: TargetOptions { mcount: "__mcount".to_string(), ..base },
+    }
+}
