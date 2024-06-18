(write-line "Hello, World from Lisp!")
(defun celsius-to-fahrenheit (celsius)
  "Convert Celsius to Fahrenheit."
  (+ (* 9/5 celsius) 32))

(defun fahrenheit-to-celsius (fahrenheit)
  "Convert Fahrenheit to Celsius."
  (/ (- fahrenheit 32) 9/5))

(defun convert-temperature ()
  "Main function to convert temperatures between Celsius and Fahrenheit."
  (format t "Temperature Converter~%")
  (format t "Choose conversion direction:~%")
  (format t "1. Celsius to Fahrenheit~%")
  (format t "2. Fahrenheit to Celsius~%")
  (let ((choice (read)))
    (cond
      ((= choice 1)
       (format t "Enter temperature in Celsius: ")
       (let ((celsius (read)))
         (format t "~%~a Celsius is ~a Fahrenheit~%"
                 celsius
                 (celsius-to-fahrenheit celsius))))
      ((= choice 2)
       (format t "Enter temperature in Fahrenheit: ")
       (let ((fahrenheit (read)))
         (format t "~%~a Fahrenheit is ~a Celsius~%"
                 fahrenheit
                 (fahrenheit-to-celsius fahrenheit))))
      (t (format t "Invalid choice. Please enter 1 or 2.~%")
         (convert-temperature)))))

;; Run the temperature converter
(convert-temperature)

