/* Copyright 2018 'markvan'
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  QMKBEST = SAFE_RANGE,
  QMKURL
};

// Enums defined for all examples:
enum {
 CT_VOLDOWN = 0,
 CT_VOLUP,
 X_TAP_DANCE
};

enum {
  TD_VOLUP_SKIP = 0,
  TD_VOLDOWN_BACK,
};
qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_VOLUP_SKIP] = ACTION_TAP_DANCE_DOUBLE(KC__VOLUP, KC_MEDIA_FAST_FORWARD),
  [TD_VOLDOWN_BACK] = ACTION_TAP_DANCE_DOUBLE(KC__VOLDOWN, KC_MEDIA_REWIND)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT( /* Base */
    KC__MUTE, TD(TD_VOLDOWN_BACK), TD(TD_VOLUP_SKIP), KC_MEDIA_PLAY_PAUSE \
  ),
};

// void dance_volup_finished (qk_tap_dance_state_t *state, void *user_data) {
//   if (state->count == 1) {
//     register_code (KC__VOLDOWN);
//     register_code (KC_MEDIA_FAST_FORWARD);
//   } else {
//     register_code (KC_MEDIA_FAST_FORWARD);
//   }
// }
//
// void dance_volup_reset (qk_tap_dance_state_t *state, void *user_data) {
//   if (state->count == 1) {
//     unregister_code (KC__VOLDOWN);
//     unregister_code (KC_MEDIA_FAST_FORWARD);
//   } else {
//     unregister_code (KC_MEDIA_FAST_FORWARD);
//   }
// }
//
// //All tap dance functions would go here. Only showing this one.
// qk_tap_dance_action_t tap_dance_actions[] = {
//  [KC__VOLUP] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_volup_finished, dance_volup_reset)
// };




bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QMKBEST:
      if (record->event.pressed) {
        // when keycode QMKBEST is pressed
        SEND_STRING("QMK is the best thing ever!");
      } else {
        // when keycode QMKBEST is released
      }
      break;
    case QMKURL:
      if (record->event.pressed) {
        // when keycode QMKURL is pressed
        SEND_STRING("https://qmk.fm/" SS_TAP(X_ENTER));
      } else {
        // when keycode QMKURL is released
      }
      break;
  }
  return true;
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
