#include <pebble.h>
#include "main_window.h"
#include <@smallstoneapps/utils/macros.h>

static Window *s_window;
static TextLayer *textLayer;

static GFont s_font;

static void on_window_load(Window *window) {
    DEBUG("MAIN: on_window_load");

    Layer *window_layer = window_get_root_layer(window);
    GRect window_rect = layer_get_frame(window_layer);

    s_font = fonts_load_custom_font(resource_get_handle(RESOURCE_ID_SUPERSCRIPT_40));

    textLayer = text_layer_create(window_rect);
    text_layer_set_font(textLayer, s_font);
    text_layer_set_text_alignment(textLayer, GTextAlignmentCenter);
    text_layer_set_text_color(textLayer, GColorBlack);
    text_layer_set_text(textLayer, "13:37");
    text_layer_set_overflow_mode(textLayer, GTextOverflowModeWordWrap);

    layer_add_child(window_layer, text_layer_get_layer(textLayer));
    text_layer_enable_screen_text_flow_and_paging(textLayer, 2);
}

static void on_window_unload(Window *window) {
    DEBUG("MAIN: on_window_unload");

    text_layer_destroy(textLayer);
    fonts_unload_custom_font(s_font);

    window_destroy(s_window);
}

static void on_select_click(ClickRecognizerRef recognizer, void *context) {
    DEBUG("MAIN: on_select_click");

    window_stack_pop(true);

}

static void click_config_provider(Window *window) {
    window_single_click_subscribe(BUTTON_ID_SELECT, (ClickHandler) on_select_click);
}

void main_window_push() {
    if (!s_window) {
        s_window = window_create();
        window_set_window_handlers(s_window, (WindowHandlers) {
                .load = on_window_load,
                .unload = on_window_unload,
        });
        window_set_click_config_provider(s_window, (ClickConfigProvider) click_config_provider);
    }
    window_stack_push(s_window, true);
}
