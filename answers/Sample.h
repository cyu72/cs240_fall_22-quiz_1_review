/**
 * QUESTION:
 * 2. What are these? Why do we use them?
 * ANSWER:
 * 2. These are header guards. We include them
 * to prevent the same class from getting defined
 * multiple times.
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
         * ANSWER:
         * 3. default constructor: Sample a;
         *    value constructor: Sample a(10, "string");
         *    copy constructor: Sample a(b);
         */
        Sample();
        Sample(int n, std::string const &str);
        Sample(Sample const &s);

        /**
         * QUESTION:
         * 4. This isn't a constructor, but we
         * need it... Why?
         *
         * 5. Why do we return a 'Sample&' instead
         * of void?
         *
         * ANSWER:
         * 4. We need it to assign the value of one Sample
         * to another.
         * Example:
         * Sample a, b;
         * a = b;
         *
         * 5. We return a `Sample&` to enable assignment chaining.
         * Example:
         * Sample a, b, c;
         * a = b = c;
         */

        Sample & operator=(Sample const &s);

        /**
         * QUESTION:
         * 6. How is the `const` keyword
         * different in these two cases?
         *
         * ANSWER:
         * 6.  the 'const' keyword in the first function ensures
         * that the string 'str' is never modified. The 'const' keyword
         * in the second ensures that the function does not modify
         * ANY member variables of the object it is called upon.
         */

        void set_str_pointer_memory(std::string const &str);
        std::string get_str_from_str_pointer() const;

        /**
         * QUESTION:
         * 7. How are these functions different?
         * ANSWER:
         * The first is pass by value, the second is pass
         * by reference. The first creates a copy (by calling the
         * copy constructor) of 'n' for the function to use/modify
         * as it likes. The second does not create a copy, allowing
         * the function to modify the 'n' that is outside of the
         * function.
         */
        void set_num_plus_5_value(int n);
        void set_num_plus_5_reference(int &n);

        /**
         * QUESTION:
         * 8. Without looking at the implementation
         * What *should* the destructor do?
         * ANSWER:
         * 8. it should use 'delete' on any dynamically
         * allocated memory belonging to the object.
         * In our case, it should 'delete' the 'str_pointer'
         */

        ~Sample();

        /**
         * QUESTION:
         * 9.What does this do?
         * Why do we define it as
         * a friend function?
         * ANSWER:
         * 9. This allows us to print the contents of our object
         * (among other things) by putting the member variables into an ostream.
         * It allows us to write the following code:
         * Sample a;
         * std::cout << a << std::endl;
         * The reason that we define it as a friend function is (in non-technical terms)
         * it really SHOULD be a member function of the ostream class, but since we can't
         * edit the ostream class source code -- we write it here and treat it like
         * a ostream member function.
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
             * ANSWER: We could have a segmentation fault from dereferencing
             * a nullpointer, or even worse, undefined behavior!
             * We don't want that!
             */
            o << *(s.str_pointer);
            return o;
        }

};



#endif
