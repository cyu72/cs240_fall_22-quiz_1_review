/**
 * QUESTION:
 * 2. What are these? Why do we use them?
 */
#ifndef SAMPLE_H
#define SAMPLE_H

#include <string>
#include <iostream>

class Sample{
    private:
        int num;
        std::string *str_pointer;

    public:
        /**
         * QUESTION:
         * 3. What are these functions? How are they different?
         *  Can you come up with the ways that they are called?
         */
        Sample();
        Sample(int n, std::string const &str);
        Sample(Sample const &s); // Const &s prevents you from modifiying s, however you do const &s because its more efficient that making a copy (in big cases)


        /**
         * QUESTION:
         * 4. This isn't a constructor, but we
         * need it... Why?
         *
         * 5. Why do we return a 'Sample&' instead
         * of void?
         */

        Sample & operator=(Sample const &s);

        /**
         * QUESTION:
         * 6. How is the `const` keyword
         * different in these two cases?
         */

        void set_str_pointer_memory(std::string const &str); // promising not to change the string
        std::string get_str_from_str_pointer() const; // promising not to change anything else in the class

        /**
         * QUESTION:
         * 7. How are these functions different?
         */
        void set_num_plus_5_value(int n);
        void set_num_plus_5_reference(int &n);

        /**
         * QUESTION:
         * 8. Without looking at the implementation
         * What *should* the destructor do?
         */

        ~Sample();

        /**
         * QUESTION:
         * 9.What does this do?
         * Why do we define it as
         * a friend function?
         */
        friend std::ostream& operator<<(std::ostream &o, Sample const &s){
            o << "num=" << s.num;
            o << " | str_pointer points to ";

            if (s.str_pointer == nullptr){
                o << "a nullptr";
                return o;
            }

            /**
             * QUESTION:
             * 10. What could happen if we didn't
             * have the above check?
             */
            o << *(s.str_pointer); // You wouldn't be able to dereference the pointer because its null (seg fault)
            return o;
        }

};



#endif
