(defun print-list (lst)
  (format t "(")
  (dolist (elem lst)
    (format t "~A " elem))
  (format t ")"))

(defun random-list (size &optional min max)
  (if (null min) (setq min 0))
  (if (null max) (setq max 100))
  (let ((lst '()))
    (dotimes (i size)
      (push (+ (random (- max min)) min) lst))
    lst))

(defun quick-sort (lst))
  
