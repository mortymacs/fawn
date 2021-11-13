#include "fawn.h"
#include <stdio.h>

void AddNewBtnClicked(GtkWidget *widget, gpointer data) {
    printf("Welcome to the Fawm demo application!\n");
}

int main(int argc, char *argv[]) {

    // Initialize Fawn.
    FawnInit(argc, argv);

    // Load CSS.
    LoadCss("demo.css");

    // Button widget.
    GtkWidget *top_btn = NewButton("Add New", "add-new");
    Action(top_btn, "clicked", AddNewBtnClicked);

    // Window widget.
    uint size[2] = {500, 200};
    GtkWidget *header = NewHeaderBar("My Application", 1, top_btn);
    GtkWidget *window = NewWindow("My Window", size, header, TRUE, "", TRUE);

    // Alter widget.
    GtkWidget *alter = NewAlert("Welcome!", "This is Fawn demo application", "welcome", TRUE);
    Attach(alter, window);

    // Box widget.
    GtkWidget *box = NewBox(true, 1);
    Attach(box, window);

    // Input widget.
    GtkWidget *input = NewInput("Enter name", "", FALSE, 25, "username", 0, 10);
    Attach(input, box);

    // Action of the big button.
    void WelcomeMessage(GtkWidget *widget, gpointer data) {
        char *username = GetEntryText(input, FALSE);
        char *welcome_message = malloc(sizeof(char) * strlen(username) + 6);
        sprintf(welcome_message, "Hello %s", username);
        GtkWidget *welcome_window = NewWindow("Welcome", size, NULL, TRUE, "", FALSE);
        GtkWidget *alter = NewAlert("Welcome!", welcome_message, "welcome-username", TRUE);
        Attach(alter, welcome_window);
    }

    // Big button widget.
    GtkWidget *big_btn = NewBigButton("Welcome Message", "Click to see the welcome message!", "bigbutton");
    Action(big_btn, "clicked", WelcomeMessage);
    Attach(big_btn, box);

    // Render the design.
    FawnRender();

    return 0;
}