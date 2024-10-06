#pragma once

#include <stdint.h>
#include <stdbool.h>
#include <time.h>
#include "defs.h"

// Multi-byte RX buffer transfer
void MD_receive_buf_init(GB_megaduck_laptop_t * periph);
void MD_receive_buf_handle_result(GB_megaduck_laptop_t * periph);
void MD_receive_buf(GB_megaduck_laptop_t * periph);

// Multi-byte TX buffer transfer
void MD_send_buf_enqueue(GB_megaduck_laptop_t * periph, uint8_t byte_to_enqueue);
void MD_send_buf_finalize_and_transmit(GB_megaduck_laptop_t * periph);
void MD_send_buf_calc_enqueue_checksum(GB_megaduck_laptop_t * periph);

// Init
void MD_init_stage_1_rx_counter(GB_megaduck_laptop_t * periph);
void MD_init_stage_3_wait_tx_count_request(GB_megaduck_laptop_t * periph);
void MD_init_stage_5_wait_tx_count_ack(GB_megaduck_laptop_t * periph);

// RTC
// void MD_rtc_set_to_local_time(GB_megaduck_laptop_t * periph);
void MD_rtc_set_from_buf(GB_megaduck_laptop_t * periph);
void MD_rtc_enqueue_reply(GB_megaduck_laptop_t * periph);

// Keyboard
void MD_keyboard_enqueue_reply(GB_megaduck_laptop_t * periph);
void MD_send_buf_handle_tx_reply(GB_megaduck_laptop_t * periph);

// Speech
void MD_speech_playback(GB_megaduck_laptop_t * periph);