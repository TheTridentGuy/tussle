#pragma once

#if defined(TUSSLE_ENABLE_PNG_LIBPNG)

#include <stdbool.h>
#include <pixman.h>

pixman_image_t *png_load(const char *path, bool gamma_correct);

#endif /* TUSSLE_ENABLE_PNG_LIBPNG */
