(define (element? a)
(and (not (null? a))
(not (pair? a))))

(define (append given order)
(foldr (lambda (ida value)
(cons (list-ref given (sub1 ida)) value))
'()
order))

(define (append given order)
(if (element? given)
given
(append (map (lambda (a) (append a order)) given)
order)))
(append 'hello 'world)