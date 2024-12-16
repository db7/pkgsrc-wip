# $NetBSD$

GITHUB_TAG=	${PKGVERSION_NOREV}
DISTNAME=	tinymist-0.12.10
CATEGORIES=	text
MASTER_SITES=	${MASTER_SITE_GITHUB:=Myriad-Dreamin/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Myriad-Dreamin/tinymist/
COMMENT=	An integrated language service for Typst
LICENSE=	apache-2.0

USE_LANGUAGES=	# none

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
