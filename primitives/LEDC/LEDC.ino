// LEDC timer precision
#define LEDC_TIMER_BIT    8

// LEDC base frequency
#define LEDC_BASE_FREQ    1000

// LEDC pin (replace with LED_BUILTIN constant for built-in LED)
#define LED_PIN           LED_BUILTIN

// Define PWM configuration
#define LEDC_START_DUTY   (0)
#define LEDC_MEAN_DUTY    (127)
#define LEDC_PEAK_DUTY    (255)
#define LEDC_BEAT_TIME    (100)
#define LEDC_THUMP_TIME   (200)
#define LEDC_PAUSE_TIME   (50)

// Attach LEDC PWM
void setup() {
  ledcAttach(LED_PIN, LEDC_BASE_FREQ, LEDC_TIMER_BIT);
}

void loop() {
  ledcFade(LED_PIN, LEDC_PEAK_DUTY, LEDC_START_DUTY, LEDC_BEAT_TIME);
  delay(LEDC_BEAT_TIME);
  ledcFade(LED_PIN, LEDC_START_DUTY, LEDC_PEAK_DUTY, LEDC_BEAT_TIME);
  delay(LEDC_BEAT_TIME + LEDC_PAUSE_TIME);

  ledcFade(LED_PIN, LEDC_PEAK_DUTY, LEDC_MEAN_DUTY, LEDC_THUMP_TIME);
  delay(LEDC_THUMP_TIME);
  ledcFade(LED_PIN, LEDC_MEAN_DUTY, LEDC_PEAK_DUTY, LEDC_THUMP_TIME);
  delay(LEDC_THUMP_TIME + LEDC_PAUSE_TIME * 3);
}
