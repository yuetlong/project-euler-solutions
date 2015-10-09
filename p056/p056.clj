(defn digit-sum [num]
  (reduce #(+ %1 (- (long %2) 48)) 0 (str num)))

(defn exp [x n]
  (reduce * (repeat n x)))

(defn p056 []
  (apply max (for [a (range 1N 100N)
                   b (range 1N 100N)]
               (digit-sum (exp a b)))))
