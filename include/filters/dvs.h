#ifndef LIBCAER_FILTERS_DVS_H_
#define LIBCAER_FILTERS_DVS_H_

#include "../events/polarity.h"

/**
 * Structure representing a single DVS pixel address,
 * with X and Y components.
 * Used in DVS filtering support.
 */
struct caer_filter_dvs_pixel {
	uint16_t x;
	uint16_t y;
};

/**
 * Pointer to DVS pixel address structure.
 */
typedef struct caer_filter_dvs_pixel *caerFilterDVSPixel;

/**
 * Pointer to DVS noise filter structure (private).
 */
typedef struct caer_filter_dvs_noise *caerFilterDVSNoise;

/**
 * Allocate memory and initialize the DVS noise filter.
 * This filter combines a HotPixel filter (high activity pixels),
 * a Background-Activity filter (uncorrelated events), and a
 * Refractory Period filter (limit event rate of a pixel).
 * The HotPixel and Background-Activity filters reduce noise due
 * to transistor mismatch, the Refractory Period filter can reduce
 * the event rate and is efficient to implement together with the
 * Background-Activity filter, requiring only one pixel memory
 * map for both.
 * At initialization, all filters are disabled. You must configure
 * and enable them using caerFilterDVSNoiseConfigSet().
 *
 * @return DVS noise filter instance, NULL on error.
 */
caerFilterDVSNoise caerFilterDVSNoiseInitialize(void);

/**
 * Destroy a DVS noise filter instance and free its memory.
 *
 * @param noiseFilter a valid DVS noise filter instance.
 */
void caerFilterDVSNoiseDestroy(caerFilterDVSNoise noiseFilter);

/**
 * Apply the DVS noise filter to the given polarity events packet.
 * This will filter out events by marking them as invalid, depending
 * on the given filter configuration.
 *
 * @param noiseFilter
 * @param polarity
 */
void caerFilterDVSNoiseApply(caerFilterDVSNoise noiseFilter, caerPolarityEventPacket polarity);

/**
 *
 * @param noiseFilter
 * @param paramAddr
 * @param param
 * @return
 */
bool caerFilterDVSNoiseConfigSet(caerFilterDVSNoise noiseFilter, uint8_t paramAddr, uint64_t param);

/**
 *
 * @param noiseFilter
 * @param paramAddr
 * @param param
 * @return
 */
bool caerFilterDVSNoiseConfigGet(caerFilterDVSNoise noiseFilter, uint8_t paramAddr, uint64_t *param);

/**
 *
 * @param noiseFilter
 * @param hotPixels
 * @return
 */
size_t caerFilterDVSNoiseConfigGetHotPixels(caerFilterDVSNoise noiseFilter, caerFilterDVSPixel *hotPixels);

/**
 * DVS HotPixel Filter:
 * Turn on learning to determine which pixels are hot, meaning very active
 * within a certain time period. In the absence of external stimuli, the
 * only pixels behaving as such must be noise.
 */
#define CAER_FILTER_DVS_HOTPIXEL_LEARN 0
/**
 * DVS HotPixel Filter:
 * Minimum time (in µs) to accumulate events for during learning.
 */
#define CAER_FILTER_DVS_HOTPIXEL_TIME 1
/**
 * DVS HotPixel Filter:
 * Minimum number of events, during the given learning time, for a
 * pixel to be considered hot.
 */
#define CAER_FILTER_DVS_HOTPIXEL_COUNT 2
/**
 * DVS HotPixel Filter:
 * Enable the hot pixel filter, filtering out the last learned hot pixels.
 */
#define CAER_FILTER_DVS_HOTPIXEL_ENABLE 3
/**
 * DVS HotPixel Filter:
 * Number of events filtered out by the hot pixel filter.
 */
#define CAER_FILTER_DVS_HOTPIXEL_STATISTICS 4

/**
 * DVS Background-Activity Filter:
 * enable the background-activity filter, which tries to remove events
 * caused by transistor leakage, by rejecting uncorrelated events.
 */
#define CAER_FILTER_DVS_BACKGROUND_ACTIVITY_ENABLE 5
/**
 * DVS Background-Activity Filter:
 * specify the time difference constant for the background-activity
 * filter in microseconds. Events that do correlated within this
 * time-frame are let through, while others are filtered out.
 */
#define CAER_FILTER_DVS_BACKGROUND_ACTIVITY_TIME 6
/**
 * DVS Background-Activity Filter:
 * number of events filtered out by the background-activity filter.
 */
#define CAER_FILTER_DVS_BACKGROUND_ACTIVITY_STATISTICS 7

/**
 * DVS Refractory Period Filter:
 * enable the refractory period filter, which limits the firing rate
 * of pixels.
 */
#define CAER_FILTER_DVS_REFRACTORY_PERIOD_ENABLE 8
/**
 * DVS Refractory Period Filter:
 * specify the time constant for the refractory period filter.
 * Pixels will be inhibited from generating new events during this
 * time after the last even has fired.
 */
#define CAER_FILTER_DVS_REFRACTORY_PERIOD_TIME 9
/**
 * DVS Refractory Period Filter:
 * number of events filtered out by the refractory period filter.
 */
#define CAER_FILTER_DVS_REFRACTORY_PERIOD_STATISTICS 10

#endif /* LIBCAER_FILTERS_DVS_H_ */
