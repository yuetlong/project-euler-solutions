(defn p072 []
  (count (distinct (for [n (range 1 1000000)
                         d (range (inc n) 1000001)
                         :when (not (and (even? n) (even? d)))
                         :when (not= 1 (numerator (/ n d)))]
                     (do (print n d "\n") (/ n d))))))
