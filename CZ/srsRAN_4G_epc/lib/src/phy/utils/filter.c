/**
 * Copyright 2013-2023 Software Radio Systems Limited
 *
 * This file is part of srsRAN.
 *
 * srsRAN is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as
 * published by the Free Software Foundation, either version 3 of
 * the License, or (at your option) any later version.
 *
 * srsRAN is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * A copy of the GNU Affero General Public License can be found in
 * the LICENSE file in the top-level directory of this distribution
 * and at http://www.gnu.org/licenses/.
 *
 */

#include "srsran/phy/utils/filter.h"
#define SRSRAN_NUM_FILTERS 8
#define SRSRAN_MAX_FILTER_SIZE 11

// clang-format off
float srsran_filt_decim2[SRSRAN_NUM_FILTERS][SRSRAN_MAX_FILTER_SIZE] = 
{
    {0.0167364016736,   0.48326359832636,   0.48326359832636,   0.01673640167364,0,0,0,0,0,0,0},
    {0.000000000000000,   0.203712369200737,   0.592575261598526,   0.203712369200737,   0.000000000000000,0,0,0,0,0,0},
    {-0.007776312719103,   0.064454645578710,   0.443321667140393,   0.443321667140393,   0.064454645578710, -0.007776312719103,0,0,0,0,0},
    {-0.008721828105097,  0.000000000000000,   0.251842786534672,  0.513758083140849,   0.251842786534672, 0.000000000000000,  -0.008721828105097,0,0,0,0},
    {-0.005164298061200,  -0.022882524920256,   0.096755650536968,   0.431291172444487,   0.431291172444487, 0.096755650536968,  -0.022882524920256,  -0.005164298061200,0,0,0},
    {-0.000000000000000,  -0.022663985459553,   0.000000000000000,   0.273977082565524,   0.497373805788057, 0.273977082565524,   0.000000000000000,  -0.022663985459553,  -0.000000000000000,0,0},
    { 0.003971846362414,  -0.011976365116169,  -0.041119498116286,   0.114687063714704,   0.434436953155337,  0.434436953155337,   0.114687063714704,  -0.041119498116286,  -0.011976365116169,   0.003971846362414,0},
    {0.005060317124845,  -0.000000000000000,  -0.041942879431345,   0.000000000000000,  0.288484826302638, 0.496795472007725,   0.288484826302638,   0.000000000000000,  -0.041942879431345,  -0.000000000000000,  0.005060317124845}
  };

float srsran_filt_decim3[SRSRAN_NUM_FILTERS][SRSRAN_MAX_FILTER_SIZE] = 
{
    {0.032388663967611,   0.467611336032389,   0.467611336032389,   0.032388663967611,0,0,0,0,0,0,0},
    {0.016883339167609,  0.227925078762723, 0.510383164139335, 0.227925078762723, 0.016883339167609,0,0,0,0,0,0},
    {0.006703633822959,   0.111127306155495,   0.382169060021546,   0.382169060021546, 0.111127306155495,   0.006703633822959,0,0,0,0,0},
    {0.000000000000000,   0.050666848023938,   0.251699825667307,   0.395266652617510, 0.251699825667307,  0.050666848023938,   0.000000000000000,0,0,0,0},
    {-0.004018779518049,   0.017806838679915,   0.150587600493065,   0.335624340345069, 0.335624340345069,   0.150587600493065,   0.017806838679915,  -0.004018779518049,0,0,0},
    {-0.005814396641997,   0.000000000000000,   0.078494354666956,   0.251550893097387,  0.351538297755307,   0.251550893097387,   0.078494354666956,   0.000000000000000,   -0.005814396641997,0,0},
    { -0.005798226803038,  -0.008741738083915,   0.030013771222565,   0.167423798937736, 0.317102394726653,   0.317102394726653,   0.167423798937736,   0.030013771222565, -0.008741738083915,  -0.005798226803038,0},
    {-0.004444793932295,  -0.011657318166992,   0.000000000000000,   0.094750202492597,  0.253394317761931,   0.335915183689516,   0.253394317761931,   0.094750202492597, 0.000000000000000,  -0.011657318166992,  -0.004444793932295},
    
};

float srsran_filt_decim4[SRSRAN_NUM_FILTERS][SRSRAN_MAX_FILTER_SIZE]  = 
{
    { 0.038579006748772,   0.461420993251228,   0.461420993251228,   0.038579006748772,0,0,0,0,0,0,0},
    {0.024553834015017,   0.234389464237986,   0.482113403493995,   0.234389464237986,   0.024553834015017,0,0,0,0,0,0},
    {0.015196373491712,   0.125956465856097,   0.358847160652191,   0.358847160652191,   0.125956465856097,   0.015196373491712,0,0,0,0,0},
    {0.008485920061584,   0.069755250084282,   0.245030941778248,   0.353455776151771,   0.245030941778248,   0.069755250084282,   0.008485920061584,0,0,0,0},
    {0.003560172702629,   0.038083722795699,   0.161031852333115,   0.297324252168557,   0.297324252168557,   0.161031852333115,   0.038083722795699,   0.003560172702629,0,0,0},
    {0.000000000000000,   0.019096925170212,   0.101875313412667,   0.230856124287772,   0.296343274258697,   0.230856124287772,   0.101875313412667,   0.019096925170212,   0.000000000000000,0,0},
    {-0.002426023829880,   0.007315224335493,  0.060635381185575,   0.169119131895270,   0.265356286413542,   0.265356286413542,   0.169119131895270,   0.060635381185575 ,  0.007315224335493,  -0.002426023829880,0},
    {-0.003871323167475,   0.000000000000000,   0.032087799410030,   0.116708621643743,   0.220701186106900,   0.268747432013603,   0.220701186106900,   0.116708621643743 ,  0.032087799410030,   0.000000000000000,-0.003871323167475}
};

// clang-format on
void srsran_filt_decim_cc_init(srsran_filt_cc_t* q, int factor, int order)
{
  q->factor       = factor;
  q->num_taps     = order + 1;
  q->is_decimator = true;
  q->taps         = srsran_vec_f_malloc(q->num_taps);

  switch (q->factor) {
    case 2:
      for (int i = 0; i < (q->num_taps); i++)
        q->taps[i] = srsran_filt_decim2[(q->num_taps) - 4][i];
      break;
    case 3:
      for (int i = 0; i < (q->num_taps); i++)
        q->taps[i] = srsran_filt_decim3[(q->num_taps) - 4][i];
      break;
    case 4:
      for (int i = 0; i < (q->num_taps); i++)
        q->taps[i] = srsran_filt_decim4[(q->num_taps) - 4][i];
      break;
    default:

      break;
  }

  for (int x = 0; x < (q->num_taps); x++) {
    printf("tap : %f.9\n", q->taps[x]);
  }
}

void srsran_filt_decim_cc_free(srsran_filt_cc_t* q)
{
  free(q->taps);
}

void srsran_filt_decim_cc_execute(srsran_filt_cc_t* q, cf_t* input, cf_t* downsampled_input, cf_t* output, int size)
{
  // we assume that "downsampled_input" made size (input/2 + order) so as to have prepended zeros //
  srsran_downsample_cc(input, downsampled_input + (q->num_taps - 1), q->factor, size);

  for (int i = 0; i < size / q->factor; i++) {
    output[i] = srsran_vec_dot_prod_cfc(&(downsampled_input[i]), q->taps, q->num_taps);
  }
}

/* Performs integer linear downsamling by a factor of M */
void srsran_downsample_cc(cf_t* input, cf_t* output, int M, int size)
{
  int i;
  for (i = 0; i < size / M; i++) {
    output[i] = input[i * M];
  }
}