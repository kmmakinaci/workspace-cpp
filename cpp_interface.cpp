#include <memory>
/*
Determine if it easy to use wrong!
Are they any reasonable error handling?
*/

/* noexcept:
    notifies the user (compiler) that a function may not
    throw an exception. If an exception thrown from that function
    `terminate` MUST be called.
*/

template<typename T>
class vector{
    public:
    bool empty() const;
};


//A factory function 
Widget *make_widget(int widget_type);
// *what happens if we igore the return value ?
// *What is possibile range of input values ?


/* rewrite => 
*/

std::unique_ptr<Widget> make_widget(int widget_type);


// ? Are enum classes easy to use wrong

// Never return a raw pointer. Consider owning_ptr / non_owning_ptr
    // or some kind of wrapper to document this

//Use noexcept to help indicate what kind of error handling being used

// Use one consistent method of reporting errors in your library

 //Do not use fopern, confusing char * inputs
 FILE *fopen(const char *pathname, const char *mode);

 using FilePtr = std::unique_ptr<FILE, decltype([](FILE *f) { fclose(f); })>;
 [[nodiscard]] FilePtr fopen(const char *pathname, const char *mode);

 [[nodiscard]] FilePtr fopen(const std::filesytem::path &path,
                                std::string_view mode);

// unfortunately this still compiles
auto file = fopen("rw+", "/my/file")

//  !!! Avoid implicit conversions / strong types

//use stronger types
//Avoid default conversions
//delete problematic overloads/ prevent conversions

template<typename WidgetType>
[[nodiscard]] WidgetType make_widget()
    requires (std::is_base_of_v<Widget, WidgetType>);