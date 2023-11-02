# Cholmod lib usually requires linking to a blas and lapack library.
# It is up to the user of this module to find a BLAS and link to it.

if (CHOLMOD_INCLUDE_DIR AND CHOLMOD_LIBRARIES)
  set(CHOLMOD_FIND_QUIETLY TRUE)
endif (CHOLMOD_INCLUDE_DIR AND CHOLMOD_LIBRARIES)

find_path(CHOLMOD_INCLUDE_DIR
  NAMES
  cholmod.h
  PATHS
  $ENV{CHOLMODDIR}
  ${INCLUDE_INSTALL_DIR}
  PATH_SUFFIXES
  suitesparse
  ufsparse
)

find_library(CHOLMOD_LIBRARY cholmod PATHS $ENV{CHOLMODDIR} ${LIB_INSTALL_DIR})
set(CHOLMOD_LIBRARIES ${CHOLMOD_LIBRARY})

if(CHOLMOD_LIBRARIES)

  get_filename_component(CHOLMOD_LIBDIR ${CHOLMOD_LIBRARIES} PATH)

  find_library(AMD_LIBRARY amd PATHS ${CHOLMOD_LIBDIR} $ENV{CHOLMODDIR} ${LIB_INSTALL_DIR})
  if (AMD_LIBRARY)
    set(CHOLMOD_LIBRARIES ${CHOLMOD_LIBRARIES} ${AMD_LIBRARY})
  else ()
    set(CHOLMOD_LIBRARIES FALSE)
  endif ()

endif(CHOLMOD_LIBRARIES)

if(CHOLMOD_LIBRARIES)

  find_library(COLAMD_LIBRARY colamd PATHS ${CHOLMOD_LIBDI