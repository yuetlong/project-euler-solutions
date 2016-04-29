(defn p057 []
  (let [e (map inc (iterate #(/ 1 (+ 2 %)) (/ 1 2)))
        d #(loop [a 0 b %] (if (> b 0) (recur (+ a 1) (quot b 10)) a))]
    (count (filter #(> (d (numerator %)) (d (denominator %))) (take 1000 e)))))
