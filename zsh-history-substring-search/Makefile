# $NetBSD: $

DISTNAME=	zsh-history-substring-search-1.1.0
CATEGORIES=	shells
MASTER_SITES=	${MASTER_SITE_GITHUB:=zsh-users/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	kikadf.01@gmail.com
COMMENT=	Fish-like history search feature for Zsh
LICENSE=	modified-bsd

DEPENDS+=	zsh-[0-9]*:../../shells/zsh

NO_BUILD=	yes
NO_CONFIGURE=	yes
USE_LANGUAGES=	# none

INSTALLATION_DIRS+=	share/${PKGBASE}

do-install:
	${INSTALL_DATA} ${WRKSRC}/${PKGBASE}.zsh \
		${DESTDIR}${PREFIX}/share/${PKGBASE}/

.include "../../mk/bsd.pkg.mk"
