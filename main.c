#include <stdbool.h>

menu *menu;
hbox *table;
tools *tools;
canvas *canvas;
colors *colors;
timeline *timeline;

int main(int argc, char **argv)
{
    menu = menu_init()
    tools = tools_init();
    canvas = canvas_init();
    colors = colors_init();
    timeline = timeline_init();

    table = hbox_new();
    hbox_add(table, tools);
    hbox_add(table, canvas);
    hbox_add(table, colors);

    window_init(600, 500, MAXIMISED | RESIZABLE);
    window_add(menu);
    window_add(table);
    window_add(timeline);
    window_show();

    while(application_is_running)
    {
        event event;
        while(poll_events(&event))
        {
            event_type type = event.type
            int pos_x = event.x
            int pos_y = event.y
            float pressure = event.pressure
            key key = event.key

            switch(event.type)
            {
                case MOUSE_DOWN:
                    if(is_in_boundary(menu, pos_x, pos_y)) menu_mouse_pressed(menu, pos_x, pos_y);
                    if(is_in_boundary(tools, pos_x, pos_y)) tools_mouse_pressed(tools, pos_x, pos_y);
                    if(is_in_boundary(canvas, pos_x, pos_y)) canvas_mouse_pressed(canvas, pos_x, pos_y, pressure);
                    if(is_in_boundary(colors, pos_x, pos_y)) colors_mouse_pressed(colors, pos_x, pos_y);
                    if(is_in_boundary(timeline, pos_x, pos_y)) timeline_mouse_pressed(timeline, pos_x, pos_y);
                    break;
                case MOUSE_MOVE:
                    if(is_in_boundary(canvas, pos_x, pos_y)) canvas_mouse_move(canvas, pos_x, pos_y, pressure);
                    if(is_in_boundary(colors, pos_x, pos_y)) colors_mouse_move(colors, pos_x, pos_y);
                    if(is_in_boundary(timeline, pos_x, pos_y)) timeline_mouse_pressed(timeline, pos_x, pos_y);
                    break;
                case MOUSE_RELEASED:
                    if(is_in_boundary(canvas, pos_x, pos_y)) canvas_mouse_released(canvas, pos_x, pos_y);
                    if(is_in_boundary(colors, pos_x, pos_y)) colors_mouse_released(colors, pos_x, pos_y);
                    if(is_in_boundary(timeline, pos_x, pos_y)) timeline_mouse_released(timeline, pos_x, pos_y)
                    break;
                case KEY_PRESSED:
                    switch(key)
                    {
                        case SPACE:
                            animation_is_playing = true;
                            break;
                        case ARROW_RIGHT:
                            move_right_on_timeline(timeline);
                            break;
                        case ARROW_LEFT:
                            move_left_on_timeline(timeline);
                            break;
                        case ARROW_UP:
                            move_up_a_layer_on_timeline(timeline);
                            break;
                        case ARROW_DOWN:
                            move_down_a_layer_on_timeline(timeline);
                    }
                    break;
            }
        }

        if(animation_is_playing) 
        {   
            block_gui();
            play_animation();
        }
    }

    return 0;
}