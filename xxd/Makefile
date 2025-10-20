# $NetBSD$

DISTNAME=	xxd-1.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=ckormanyos/}
GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ckormanyos/xxd/
COMMENT=	hex-dump-type utility xxd
#LICENSE=	# TODO: (see mk/license.mk)

USE_LANGUAGES=	c c++

WRKSRC=	${WRKDIR}/${DISTNAME}

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
