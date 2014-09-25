open('number_rotations_dim.mat')
subplot(1,2,1)
plot(n_step,Rotations,'-o');
xlabel('n_{step}');
ylabel('Number of rotations');

subplot(1,2,2)
plot(n_step.^2,Rotations,'-o');
xlabel('n_{step}^2');
ylabel('Number of rotations');