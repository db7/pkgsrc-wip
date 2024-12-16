# $NetBSD$

GITHUB_TAG=	${PKGVERSION_NOREV}
DISTNAME=	libvsync-4.0.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=open-s4c/}

MAINTAINER=	db7@sdf.org
HOMEPAGE=	https://github.com/open-s4c/libvsync/
COMMENT=	Concurrency library verified for WMM systems
#LICENSE=	mit

USE_LANGUAGES=	c
CMAKE_FLAGS= -DLIBVSYNC_BUILD_TESTS=off

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
