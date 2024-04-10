# $NetBSD$

DISTNAME=	elvish-0.21.0
CATEGORIES=	shells
MASTER_SITES=	${MASTER_SITE_GITHUB:=elves/}
GITHUB_TAG=	abbf9c6d87b2056e23c94e6d79da2e265ddbfadf

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://elv.sh/
COMMENT=	Expressive programming language and a versatile interactive shell
LICENSE=	2-clause-bsd

GO_VERSION_REQD+=	122

INSTALLATION_DIRS=	bin
PKG_SHELL=		bin/elvish

USE_TOOLS+=		perl gmake

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/elvish \
		${DESTDIR}${PREFIX}/bin

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
