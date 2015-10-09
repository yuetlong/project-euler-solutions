(defn p055 []
  (letfn [(reverse-num-as-str [num] (reduce str "" (drop-while #(= % \0) (reverse (str num)))))
          (reverse-num-as-num [num] (read-string (reverse-num-as-str num)))
          (add-reverse [num] (+ (reverse-num-as-num num) num))
          (palindrome? [num] (= (str num) (reverse-num-as-str num)))
          (lychrel?    [num] (not-any? palindrome? (take 50 (rest (iterate add-reverse num)))))]
    (print (filter lychrel? (range 10N 10000N)))))
