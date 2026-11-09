import { render, screen, fireEvent } from '@testing-library/react';
import axios from 'axios';
import App from './App';

jest.mock('axios', () => ({ get: jest.fn() }));

test('renders the search box', () => {
  render(<App />);
  expect(screen.getByText('Weather App')).toBeInTheDocument();
  expect(screen.getByPlaceholderText('Enter City Name..')).toBeInTheDocument();
});

test('shows weather for a city', async () => {
  axios.get.mockResolvedValue({
    data: {
      name: 'Long Beach',
      sys: { country: 'US' },
      main: { temp: 71.6 },
      weather: [{ icon: '01d', description: 'clear sky' }],
      wind: { speed: 5.4 },
    },
  });
  render(<App />);
  const input = screen.getByPlaceholderText('Enter City Name..');
  fireEvent.change(input, { target: { value: 'Long Beach' } });
  fireEvent.keyDown(input, { key: 'Enter' });

  expect(await screen.findByText(/Long Beach/)).toBeInTheDocument();
  expect(screen.getByText('US')).toBeInTheDocument();
  expect(screen.getByText('72')).toBeInTheDocument();
  expect(screen.getByText('CLEAR SKY')).toBeInTheDocument();
  expect(screen.getByText('Wind Speed: 5.4mph')).toBeInTheDocument();
  expect(axios.get.mock.calls[0][1].params).toMatchObject({ q: 'Long Beach', units: 'imperial' });
});

test('shows an error when the city is not found', async () => {
  axios.get.mockRejectedValue(new Error('404'));
  render(<App />);
  const input = screen.getByPlaceholderText('Enter City Name..');
  fireEvent.change(input, { target: { value: 'notacity' } });
  fireEvent.keyDown(input, { key: 'Enter' });

  expect(await screen.findByText('City not found')).toBeInTheDocument();
});
