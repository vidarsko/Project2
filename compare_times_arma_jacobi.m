open('compare_times_arma_jacobi.mat');

subplot(2,2,1)
[haxes,hline1,hline2] = plotyy(n_step,jacobi,n_step,armadillo);
ylabel(haxes(1),'Time elapsed Jacobi [s]');
ylabel(haxes(2),'Time elapsed Armadillo [s]');
xlabel(haxes(2),'n_{step}')
set(hline1, 'LineStyle','-','marker','o','color','red')
set(hline2, 'LineStyle','-','marker','o','color','blue')
set(haxes(2),'YColor','r')

%Compare semilog
subplot(2,2,2)
semilogy(n_step,jacobi,'bo-')
hold on
semilogy(n_step,armadillo,'ro-')
xlabel('n_{step}')
ylabel('Time elapsed[s]')
legend('Jacobi algorithm', 'Armadillo algorithm')

%jacobi app
subplot(2,2,3)
n_jacobi = n_step.^4.0;
plot(n_jacobi,jacobi,'bo-');
xlabel('(n_{step})^{4.0}')
ylabel('Time elapsed[s]')

%armadillo app
subplot(2,2,4)
n_armadillo = n_step.^2.5;
plot(n_armadillo,armadillo,'ro-');
xlabel('(n_{step})^{2.5}')
ylabel('Time elapsed[s]')
