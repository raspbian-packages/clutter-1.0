/*
 * Clutter.
 *
 * An OpenGL based 'interactive canvas' library.
 *
 * Copyright © 2009, 2010, 2011  Intel Corp.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library. If not, see <http://www.gnu.org/licenses/>.
 *
 * Author: Emmanuele Bassi <ebassi@linux.intel.com>
 */

#ifndef __CLUTTER_INPUT_DEVICE_H__
#define __CLUTTER_INPUT_DEVICE_H__

#if !defined(__CLUTTER_H_INSIDE__) && !defined(CLUTTER_COMPILATION)
#error "Only <clutter/clutter.h> can be included directly."
#endif

#include <clutter/clutter-types.h>

G_BEGIN_DECLS

#define CLUTTER_TYPE_INPUT_DEVICE               (clutter_input_device_get_type ())
#define CLUTTER_INPUT_DEVICE(obj)               (G_TYPE_CHECK_INSTANCE_CAST ((obj), CLUTTER_TYPE_INPUT_DEVICE, ClutterInputDevice))
#define CLUTTER_IS_INPUT_DEVICE(obj)            (G_TYPE_CHECK_INSTANCE_TYPE ((obj), CLUTTER_TYPE_INPUT_DEVICE))
#define CLUTTER_INPUT_DEVICE_CLASS(klass)       (G_TYPE_CHECK_CLASS_CAST ((klass), CLUTTER_TYPE_INPUT_DEVICE, ClutterInputDeviceClass))
#define CLUTTER_IS_INPUT_DEVICE_CLASS(klass)    (G_TYPE_CHECK_CLASS_TYPE ((klass), CLUTTER_TYPE_INPUT_DEVICE))
#define CLUTTER_INPUT_DEVICE_GET_CLASS(obj)     (G_TYPE_INSTANCE_GET_CLASS ((obj), CLUTTER_TYPE_INPUT_DEVICE, ClutterInputDeviceClass))

/**
 * ClutterInputDevice:
 *
 * Generic representation of an input device. The actual contents of this
 * structure depend on the backend used.
 */
typedef struct _ClutterInputDeviceClass ClutterInputDeviceClass;

CLUTTER_AVAILABLE_IN_1_0
GType clutter_input_device_get_type (void) G_GNUC_CONST;

CLUTTER_AVAILABLE_IN_1_0
ClutterInputDeviceType  clutter_input_device_get_device_type    (ClutterInputDevice  *device);
CLUTTER_AVAILABLE_IN_1_0
gint                    clutter_input_device_get_device_id      (ClutterInputDevice  *device);

CLUTTER_AVAILABLE_IN_1_12
gboolean                clutter_input_device_get_coords        (ClutterInputDevice   *device,
                                                                ClutterEventSequence *sequence,
                                                                ClutterPoint         *point);
CLUTTER_AVAILABLE_IN_1_16
ClutterModifierType     clutter_input_device_get_modifier_state (ClutterInputDevice  *device);
CLUTTER_AVAILABLE_IN_1_2
ClutterActor *          clutter_input_device_get_pointer_actor  (ClutterInputDevice  *device);
CLUTTER_AVAILABLE_IN_1_2
ClutterStage *          clutter_input_device_get_pointer_stage  (ClutterInputDevice  *device);
CLUTTER_AVAILABLE_IN_1_2
const gchar *           clutter_input_device_get_device_name    (ClutterInputDevice  *device);
CLUTTER_AVAILABLE_IN_1_2
ClutterInputMode        clutter_input_device_get_device_mode    (ClutterInputDevice  *device);
CLUTTER_AVAILABLE_IN_1_2
gboolean                clutter_input_device_get_has_cursor     (ClutterInputDevice  *device);
CLUTTER_AVAILABLE_IN_1_2
void                    clutter_input_device_set_enabled        (ClutterInputDevice  *device,
                                                                 gboolean             enabled);
CLUTTER_AVAILABLE_IN_1_2
gboolean                clutter_input_device_get_enabled        (ClutterInputDevice  *device);

CLUTTER_AVAILABLE_IN_1_2
guint                   clutter_input_device_get_n_axes         (ClutterInputDevice  *device);
CLUTTER_AVAILABLE_IN_1_2
ClutterInputAxis        clutter_input_device_get_axis           (ClutterInputDevice  *device,
                                                                 guint                index_);
CLUTTER_AVAILABLE_IN_1_2
gboolean                clutter_input_device_get_axis_value     (ClutterInputDevice  *device,
                                                                 gdouble             *axes,
                                                                 ClutterInputAxis     axis,
                                                                 gdouble             *value);

CLUTTER_AVAILABLE_IN_1_2
guint                   clutter_input_device_get_n_keys         (ClutterInputDevice  *device);
CLUTTER_AVAILABLE_IN_1_2
void                    clutter_input_device_set_key            (ClutterInputDevice  *device,
                                                                 guint                index_,
                                                                 guint                keyval,
                                                                 ClutterModifierType  modifiers);
CLUTTER_AVAILABLE_IN_1_2
gboolean                clutter_input_device_get_key            (ClutterInputDevice  *device,
                                                                 guint                index_,
                                                                 guint               *keyval,
                                                                 ClutterModifierType *modifiers);

CLUTTER_AVAILABLE_IN_1_2
ClutterInputDevice *    clutter_input_device_get_associated_device (ClutterInputDevice *device);
CLUTTER_AVAILABLE_IN_1_2
GList *                 clutter_input_device_get_slave_devices  (ClutterInputDevice  *device);

CLUTTER_AVAILABLE_IN_1_2
void                    clutter_input_device_update_from_event  (ClutterInputDevice  *device,
                                                                 ClutterEvent        *event,
                                                                 gboolean             update_stage);

CLUTTER_AVAILABLE_IN_1_10
void                    clutter_input_device_grab               (ClutterInputDevice  *device,
                                                                 ClutterActor        *actor);
CLUTTER_AVAILABLE_IN_1_10
void                    clutter_input_device_ungrab             (ClutterInputDevice  *device);
CLUTTER_AVAILABLE_IN_1_10
ClutterActor *          clutter_input_device_get_grabbed_actor  (ClutterInputDevice  *device);

CLUTTER_AVAILABLE_IN_1_12
void                    clutter_input_device_sequence_grab      (ClutterInputDevice   *device,
                                                                 ClutterEventSequence *sequence,
                                                                 ClutterActor         *actor);
CLUTTER_AVAILABLE_IN_1_12
void                    clutter_input_device_sequence_ungrab    (ClutterInputDevice   *device,
                                                                 ClutterEventSequence *sequence);
CLUTTER_AVAILABLE_IN_1_12
ClutterActor *          clutter_input_device_sequence_get_grabbed_actor (ClutterInputDevice   *device,
                                                                         ClutterEventSequence *sequence);

CLUTTER_AVAILABLE_IN_1_10
gboolean                clutter_input_device_keycode_to_evdev   (ClutterInputDevice *device,
                                                                 guint               hardware_keycode,
                                                                 guint              *evdev_keycode);

CLUTTER_AVAILABLE_IN_1_22
const gchar *           clutter_input_device_get_vendor_id      (ClutterInputDevice *device);
CLUTTER_AVAILABLE_IN_1_22
const gchar *           clutter_input_device_get_product_id     (ClutterInputDevice *device);

G_END_DECLS

#endif /* __CLUTTER_INPUT_DEVICE_H__ */
