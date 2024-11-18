$NetBSD$

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- net/socket/udp_socket_unittest.cc.orig	2024-11-14 01:04:11.165629600 +0000
+++ net/socket/udp_socket_unittest.cc
@@ -372,7 +372,7 @@ TEST_F(UDPSocketTest, PartialRecv) {
   EXPECT_EQ(second_packet, received);
 }
 
-#if BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
 // - MacOS: requires root permissions on OSX 10.7+.
 // - Android: devices attached to testbots don't have default network, so
 // broadcasting to 255.255.255.255 returns error -109 (Address not reachable).
@@ -683,7 +683,7 @@ TEST_F(UDPSocketTest, ClientSetDoNotFrag
     EXPECT_THAT(rv, IsOk());
 
     rv = client.SetDoNotFragment();
-#if BUILDFLAG(IS_IOS) || BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_IOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
     // TODO(crbug.com/42050633): IP_MTU_DISCOVER is not implemented on Fuchsia.
     EXPECT_THAT(rv, IsError(ERR_NOT_IMPLEMENTED));
 #else
@@ -705,7 +705,7 @@ TEST_F(UDPSocketTest, ServerSetDoNotFrag
     EXPECT_THAT(rv, IsOk());
 
     rv = server.SetDoNotFragment();
-#if BUILDFLAG(IS_IOS) || BUILDFLAG(IS_FUCHSIA)
+#if BUILDFLAG(IS_IOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
     // TODO(crbug.com/42050633): IP_MTU_DISCOVER is not implemented on Fuchsia.
     EXPECT_THAT(rv, IsError(ERR_NOT_IMPLEMENTED));
 #else
@@ -764,7 +764,7 @@ TEST_F(UDPSocketTest, JoinMulticastGroup
 
 // TODO(crbug.com/40620614): failing on device on iOS 12.2.
 // TODO(crbug.com/40189274): flaky on Mac 11.
-#if BUILDFLAG(IS_IOS) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_IOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 #define MAYBE_SharedMulticastAddress DISABLED_SharedMulticastAddress
 #else
 #define MAYBE_SharedMulticastAddress SharedMulticastAddress
@@ -818,7 +818,7 @@ TEST_F(UDPSocketTest, MAYBE_SharedMultic
                                 NetLogSource());
   ASSERT_THAT(client_socket.Connect(send_address), IsOk());
 
-#if !BUILDFLAG(IS_CHROMEOS_ASH)
+#if !BUILDFLAG(IS_CHROMEOS_ASH) && !BUILDFLAG(IS_BSD)
   // Send a message via the multicast group. That message is expected be be
   // received by both receving sockets.
   //
