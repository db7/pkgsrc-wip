# $NetBSD$

DISTNAME=	llama.cpp-${GITHUB_TAG}
PKGNAME=	${DISTNAME:S/-b/-0.0.2./}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=ggerganov/}
GITHUB_TAG=	b4233

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ggerganov/llama.cpp/
COMMENT=	LLM inference in C/C++
LICENSE=	mit

USE_TOOLS+=		pkg-config
USE_LANGUAGES=		c c++
USE_CXX_FEATURES=	gnu++17

BLAS_INDEX64=		yes
BLAS_ACCEPTED=		openblas_pthread #openblas_openmp
BLAS_C_INTERFACE=	yes
CXXFLAGS+=		${BLAS_INCLUDES}

PKGCONFIG_OVERRIDE+=	cmake/llama.pc.in
REPLACE_PYTHON+=	*.py */*.py */*/*.py

CMAKE_CONFIGURE_ARGS+=	-DGGML_BLAS=ON
CMAKE_CONFIGURE_ARGS+=	-DGGML_BLAS_VENDOR=OpenBLAS
CMAKE_CONFIGURE_ARGS+=	-DBLAS_LIBRARIES=${CBLAS_LIBS:Q}
CMAKE_CONFIGURE_ARGS+=	-DLLAMA_BUILD_TESTS=no
CMAKE_CONFIGURE_ARGS+=	-DGGML_OPENCL_EMBED_KERNELS=OFF
CMAKE_CONFIGURE_ARGS+=	-DGGML_OPENCL_PROFILING=OFF
CMAKE_CONFIGURE_ARGS+=	-DGGML_OPENCL_USE_ADRENO_KERNELS=OFF

.include "../../devel/cmake/build.mk"
.include "../../lang/python/application.mk"
.include "../../mk/blas.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
